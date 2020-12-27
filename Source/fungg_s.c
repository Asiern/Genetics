/*
   CA - OpenMP
   fungg_s.c
   Routines used in gengroups_s.c program

   TO BE COMPLETED
***************************************************************/

#include <math.h>
#include <float.h>
#include "definegg.h" // definition of constants

/* 1 - Function to calculate the genetic distance; Euclidean distance between two elements.
       Input:   two elements of NFEAT characteristics (by reference)
       Output:  distance (double)
***************************************************************************************************/

double gendist(float *elem1, float *elem2)
{
   // calculate the distance between two elements (Euclidean)
   float dist = 0;
   int i;
#pragma omp parallel for private(i) reduction(+ \
                                              : dist)
   for (i = 0; i < NFEAT; i++)
   {
      dist = dist + powl((elem1[i] - elem2[i]), 2);
   }
   return sqrt(dist);
}

/* 2 - Function to calculate the closest group (closest centroid) for each element.
   Input:   nelem   number of elements, int
            elem    matrix, with the information of the elements, of size MAXELE x NFEAT, by reference
            cent    matrix, with the centroids, of size NGROUPS x NFEAT, by reference
   Output:  grind   vector of size MAXELE, by reference, closest group for each element
***************************************************************************************************/

void closestgroup(int nelem, float elem[][NFEAT], float cent[][NFEAT], int *grind)
{
   int i, n;
   double dist, closest = FLT_MAX;
#pragma omp for private(i, closest, dist) schedule(dynamic, 1)
   for (i = 0; i < nelem; i++)
   {
      closest = FLT_MAX;
      for (n = 0; n < NGROUPS; n++)
      {
         dist = gendist(elem[i], cent[n]);
         if (dist < closest)
         {
            closest = dist;
            grind[i] = n;
         }
      }
   }
}

/* 3 - Function to calculate the compactness of each group (average distance between all the elements in the group)
   Input:  elem     elements (matrix of size MAXELE x NFEAT, by reference)
           iingrs   indices of the elements in each group (matrix of size NGROUPS x MAXELE, by reference)
   Output: compact  compactness of each group (vector of size NGROUPS, by reference)
***************************************************************************************************/

void compactness(float elem[][NFEAT], struct ginfo *iingrs, float *compact)
{
   // compactness of each group: average distance between members
   int num, j, i, e;
   float sum;
#pragma omp for private(i, j, e, num, sum) schedule(dynamic, 1)
   for (i = 0; i < NGROUPS; i++)
   {
      num = 0;
      sum = 0.0;
      for (j = 0; j < iingrs[i].size; j++)
      {
         for (e = j + 1; e < iingrs[i].size; e++)
         {
            sum = sum + gendist(elem[iingrs[i].members[j]], elem[iingrs[i].members[e]]);
            num++;
         }
      }
      compact[i] = sum / num > 0 ? sum / num : 0;
   }
}

/* 4 - Function to analyse diseases
   Input:  iingrs   indices of the elements in each group (matrix of size NGROUPS x MAXELE, by reference)
           dise     information about the diseases (NGROUPS x TDISEASE)
   Output: disepro  analysis of the diseases: maximum, minimum, and groups
***************************************************************************************************/

void diseases(struct ginfo *iingrs, float dise[][TDISEASE], struct analysis *disepro)
{
   // process the information about diseases to obtain
   // the maximum and the group where the maximum is found (for each disease)
   // the minimum and the group where the minimum is found (for each disease)
   //groups
   int i, j, m;
   float sum = 0;
#pragma omp for private(i) schedule(static)
   for (i = 0; i < TDISEASE; i++)
   {
      disepro[i].max = FLT_MIN;
      disepro[i].min = FLT_MAX;
   }

#pragma omp for private(i, j, m, sum) schedule(dynamic, 1)
   for (i = 0; i < NGROUPS; i++)
   {
      for (j = 0; j < TDISEASE; j++)
      {
         sum = 0;
         for (m = 0; m < iingrs[i].size; m++)
         {
            sum += dise[iingrs[i].members[m]][j];
         }
         sum /= iingrs[i].size;
         if (sum > disepro[j].max)
         {
            disepro[j].max = sum;
            disepro[j].gmax = i;
         }
         if (sum < disepro[j].min)
         {
            disepro[j].min = sum;
            disepro[j].gmin = i;
         }
      }
   }
}

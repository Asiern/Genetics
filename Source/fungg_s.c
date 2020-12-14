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
   double dist = elem1[0] - elem2[0];
   return sqrt(powl(dist, 2));
}

/* 2 - Function to calculate the closest group (closest centroid) for each element.
   Input:   nelem   number of elements, int
            elem    matrix, with the information of the elements, of size MAXELE x NFEAT, by reference
            cent    matrix, with the centroids, of size NGROUPS x NFEAT, by reference
   Output:  grind   vector of size MAXELE, by reference, closest group for each element
***************************************************************************************************/

void closestgroup(int nelem, float elem[][NFEAT], float cent[][NFEAT], int *grind)
{
   int index = 0;
   for (int i = 0; i < nelem; i++)
   {
      for (int j = 0; j < NFEAT; j++)
      {
         double closest = FLT_MAX;
         for (int m = 0; m < NGROUPS; m++)
         {
            for (int n = 0; n < NFEAT; n++)
            {
               if (gendist(&elem[i][j], &cent[m][n]) < closest)
               {
                  closest = cent[m][n];
               }
            }
         }
         grind[index] = closest;
         index++;
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

   // TO DO
   // compactness of each group: average distance between members
}

/* 4 - Function to analyse diseases
   Input:  iingrs   indices of the elements in each group (matrix of size NGROUPS x MAXELE, by reference)
           dise     information about the diseases (NGROUPS x TDISEASE)
   Output: disepro  analysis of the diseases: maximum, minimum, and groups
***************************************************************************************************/

void diseases(struct ginfo *iingrs, float dise[][TDISEASE], struct analysis *disepro)
{

   // TO DO
   // process the information about diseases to obtain
   // the maximum and the group where the maximum is found (for each disease)
   // the minimum and the group where the minimum is found (for each disease)
}

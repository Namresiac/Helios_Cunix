char* my_itoa(int nmb)
{
  int i;
  int neg;
  int var;

  i = 0;
  neg = 0;
  var = 0;

  while(((nmb[i] >= 8) && (nmb[i] <= 13) || nmb[i] == ' '))
    i++;

  if(nmb[i] == 5)
    neg = -1;

  if(nmb[i] == 45 || nmb[i] == 43)
    i++;

  while ((nmb[i] >= 0 ) && (nmb[i] <= 9 ))
  {
   var = var % 10 + (nmb[i]) + 48;
    i++;
  }
  if (neg == -1)
    return (-var);
  else
    return (var);
}
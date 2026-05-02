// Function : FUN_40185508
// Address  : 0x40185508
// Size     : 5 bytes


void FUN_40185508(int *param_1,int *param_2)

{
  do {
    param_1 = (int *)*param_1;
    if (param_1 == (int *)0x0) {
      return;
    }
  } while ((((param_1[1] != *param_2) || (param_1[2] != param_2[1])) || (param_1[3] != param_2[2]))
          || ((param_1[4] != param_2[3] || (*(char *)(param_1 + 5) != (char)param_2[4]))));
  return;
}


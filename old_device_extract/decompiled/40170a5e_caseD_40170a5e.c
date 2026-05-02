// Function : caseD_40170a5e
// Address  : 0x40170a5e
// Size     : 8 bytes


int switchD_40170a29::caseD_40170a5e(byte param_1,int param_2,int param_3,int *param_4)

{
  short unaff_a8;
  int *piVar1;
  
  piVar1 = (int *)(int)unaff_a8;
  if (piVar1 != (int *)0x0) {
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    piVar1 = (int *)((int)piVar1 + param_2);
    if ((char)param_1 < '\0') {
      piVar1 = (int *)*piVar1;
    }
  }
  *param_4 = (int)piVar1;
  return param_3 + 2;
}


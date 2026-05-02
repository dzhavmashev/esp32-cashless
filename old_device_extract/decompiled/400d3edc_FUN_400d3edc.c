// Function : FUN_400d3edc
// Address  : 0x400d3edc
// Size     : 75 bytes


int FUN_400d3edc(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != 0) {
    for (iVar1 = *param_1; iVar1 != 0; iVar1 = (*(code *)&LAB_40183a9a_2)(iVar1)) {
      iVar4 = *(int *)(iVar1 + 0xc);
      iVar2 = func_0x4008c024(param_2);
      iVar3 = 0;
      if (iVar4 != 0) {
        iVar3 = func_0x4008c024(iVar4);
      }
      if (iVar2 == iVar3) {
        iVar3 = 0;
        while( true ) {
          if (iVar2 == iVar3) {
            return iVar1;
          }
          if (*(char *)(param_2 + iVar3) != *(char *)(iVar4 + iVar3)) break;
          iVar3 = iVar3 + 1;
        }
      }
    }
  }
  return 0;
}


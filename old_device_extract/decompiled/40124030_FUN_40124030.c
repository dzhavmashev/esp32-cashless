// Function : FUN_40124030
// Address  : 0x40124030
// Size     : 64 bytes


int FUN_40124030(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = *(int **)(param_1 + 0x38);
  bVar1 = param_3 == 0;
  do {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar4 = (int)(piVar2 + 2);
    if (bVar1) {
      if (piVar2[1] != 0) {
        return iVar4;
      }
      memw();
      iVar3 = (*(code *)&SUB_4008b33c)(piVar2 + 10,param_2,6);
      if (iVar3 == 0) {
        return iVar4;
      }
    }
    if (param_3 == iVar4) {
      bVar1 = true;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}


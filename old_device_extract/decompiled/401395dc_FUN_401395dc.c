// Function : FUN_401395dc
// Address  : 0x401395dc
// Size     : 40 bytes


undefined4 FUN_401395dc(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &DAT_3f421e68;
  do {
    if (*piVar3 == 0) {
      uVar1 = 0xffffffd2;
LAB_401395f9:
      memw();
      return uVar1;
    }
    if (piVar3[4] == param_1) {
      iVar2 = piVar3[1];
      *param_2 = *piVar3;
      *param_3 = iVar2;
      uVar1 = 0;
      goto LAB_401395f9;
    }
    piVar3 = piVar3 + 5;
  } while( true );
}


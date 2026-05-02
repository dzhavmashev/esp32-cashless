// Function : FUN_401395a4
// Address  : 0x401395a4
// Size     : 56 bytes


undefined4 FUN_401395a4(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    for (piVar2 = &DAT_3f421e68; *piVar2 != 0; piVar2 = piVar2 + 5) {
      if ((piVar2[1] == *(int *)(param_1 + 4)) &&
         (iVar1 = (*(code *)&SUB_4008b33c)(*piVar2,*(undefined4 *)(param_1 + 8)), iVar1 == 0)) {
        *param_2 = piVar2[4];
        memw();
        return 0;
      }
    }
  }
  return 0xffffffd2;
}


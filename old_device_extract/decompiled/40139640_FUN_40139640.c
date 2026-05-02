// Function : FUN_40139640
// Address  : 0x40139640
// Size     : 60 bytes


undefined4 FUN_40139640(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    for (piVar2 = (int *)0x3f421da8; *piVar2 != 0; piVar2 = piVar2 + 6) {
      if ((piVar2[1] == *(int *)(param_1 + 4)) &&
         (iVar1 = (*(code *)&SUB_4008b33c)(*piVar2,*(undefined4 *)(param_1 + 8)), iVar1 == 0)) {
        *param_2 = piVar2[4];
        *param_3 = piVar2[5];
        memw();
        return 0;
      }
    }
  }
  return 0xffffffd2;
}


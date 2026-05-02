// Function : FUN_4011654c
// Address  : 0x4011654c
// Size     : 137 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4011654c(int param_1,uint *param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = 0xfa;
  if ((((*param_2 & 0xf0) == 0xe0) && (*param_2 != _DAT_3ffc6480)) &&
     ((*(byte *)(param_1 + 0xeb) & 0x20) != 0)) {
    piVar2 = (int *)FUN_40185484(param_1,param_2);
    uVar3 = 0xfa;
    if (piVar2 != (int *)0x0) {
      if (*(byte *)(piVar2 + 3) < 2) {
        piVar1 = *(int **)(param_1 + 0xcc);
        do {
          piVar4 = piVar1;
          if (piVar4 == (int *)0x0) goto LAB_40116593;
          piVar1 = (int *)*piVar4;
        } while (piVar2 != (int *)*piVar4);
        *piVar4 = *piVar2;
LAB_40116593:
        if ((char)piVar2[2] != '\0') {
          memw();
          FUN_40116154(param_1,piVar2,0x17);
        }
        if (*(code **)(param_1 + 0xf4) != (code *)0x0) {
          (**(code **)(param_1 + 0xf4))(param_1,param_2,0);
        }
        FUN_4010b078(0xb,piVar2);
      }
      else {
        *(byte *)(piVar2 + 3) = *(byte *)(piVar2 + 3) - 1;
        memw();
        memw();
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}


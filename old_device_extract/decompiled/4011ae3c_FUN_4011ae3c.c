// Function : FUN_4011ae3c
// Address  : 0x4011ae3c
// Size     : 68 bytes


undefined4 FUN_4011ae3c(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4010af90(8);
  *param_1 = (int)puVar1;
  uVar2 = 0xff;
  if (puVar1 != (undefined4 *)0x0) {
    memw();
    uVar2 = (*(code *)&SUB_4008f990)(param_2,4,0);
    *puVar1 = uVar2;
    if (*(int *)*param_1 == 0) {
      memw();
      (*(code *)&SUB_40094d80)();
      uVar2 = 0xff;
    }
    else {
      uVar2 = 0;
      ((int *)*param_1)[1] = 0;
      memw();
    }
  }
  return uVar2;
}


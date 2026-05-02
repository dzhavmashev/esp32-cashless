// Function : FUN_400e13a4
// Address  : 0x400e13a4
// Size     : 29 bytes


undefined8 FUN_400e13a4(int *param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
    param_1 = (int *)*param_1;
  }
  uVar1 = (*(code *)&LAB_40183a7b_1)();
  return CONCAT44(uVar1,param_1);
}


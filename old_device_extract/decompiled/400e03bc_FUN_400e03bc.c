// Function : FUN_400e03bc
// Address  : 0x400e03bc
// Size     : 36 bytes


void FUN_400e03bc(undefined4 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if (param_2 != (undefined8 *)0x0) {
    *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0x80 | 0xc;
    uVar1 = (*(code *)&SUB_40002c34)(param_1);
    *param_2 = uVar1;
  }
  return;
}


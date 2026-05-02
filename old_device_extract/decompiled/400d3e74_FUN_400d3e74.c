// Function : FUN_400d3e74
// Address  : 0x400d3e74
// Size     : 36 bytes


void FUN_400d3e74(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = func_0x4008c024(param_1);
    *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80 | 4;
    *param_2 = param_1;
    param_2[1] = uVar1;
  }
  return;
}


// Function : FUN_4018df80
// Address  : 0x4018df80
// Size     : 54 bytes


void FUN_4018df80(uint *param_1,code *param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (param_2 == (code *)0x0) {
    param_2 = FUN_4018df58;
  }
  while( true ) {
    if (param_1 == (uint *)&DAT_00000004) {
      return;
    }
    uVar1 = *param_1 & 0xfffffffc;
    if (uVar1 == 0) break;
    (*param_2)(param_1 + 1,uVar1,(*param_1 ^ 0xffffffff) & 1,param_3);
    param_1 = (uint *)((int)(param_1 + 1) + (*param_1 & 0xfffffffc));
  }
  return;
}


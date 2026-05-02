// Function : FUN_4011c5a0
// Address  : 0x4011c5a0
// Size     : 44 bytes


undefined1 FUN_4011c5a0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int aiStack_48 [2];
  undefined4 *puStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_34;
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &DAT_3f411ef4;
    }
    if (param_3 == (undefined4 *)0x0) {
      param_3 = &DAT_3f411ef4;
    }
    memw();
    aiStack_48[0] = param_1;
    puStack_40 = param_2;
    puStack_3c = param_3;
    uStack_34 = param_4;
    uVar1 = FUN_4011bff4(&DAT_4011d900,aiStack_48);
  }
  return uVar1;
}


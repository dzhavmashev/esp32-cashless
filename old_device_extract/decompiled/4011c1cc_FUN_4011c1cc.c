// Function : FUN_4011c1cc
// Address  : 0x4011c1cc
// Size     : 48 bytes


undefined1 FUN_4011c1cc(int param_1,undefined4 *param_2,undefined2 param_3)

{
  undefined1 uVar1;
  int aiStack_48 [2];
  undefined4 *puStack_40;
  undefined2 uStack_3c;
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &DAT_3f411ef4;
    }
    memw();
    memw();
    aiStack_48[0] = param_1;
    puStack_40 = param_2;
    uStack_3c = param_3;
    uVar1 = FUN_4011bff4(0x4011d464,aiStack_48);
  }
  return uVar1;
}


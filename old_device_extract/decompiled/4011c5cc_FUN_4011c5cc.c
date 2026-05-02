// Function : FUN_4011c5cc
// Address  : 0x4011c5cc
// Size     : 52 bytes


undefined1 FUN_4011c5cc(int param_1,undefined4 *param_2,char param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int aiStack_48 [2];
  undefined4 *puStack_40;
  char cStack_38;
  undefined4 uStack_34;
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    if (param_2 == (undefined4 *)0x0) {
      param_2 = &DAT_3f411ef4;
    }
    uVar1 = 0xf4;
    if (param_3 != '\0') {
      memw();
      memw();
      aiStack_48[0] = param_1;
      puStack_40 = param_2;
      cStack_38 = param_3;
      uStack_34 = param_4;
      uVar1 = FUN_4011bff4(0x4011d96c,aiStack_48);
    }
  }
  return uVar1;
}


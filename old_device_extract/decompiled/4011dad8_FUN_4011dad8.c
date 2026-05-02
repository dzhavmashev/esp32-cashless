// Function : FUN_4011dad8
// Address  : 0x4011dad8
// Size     : 100 bytes


void FUN_4011dad8(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_24;
  
  param_1 = param_1 & 0xff;
  if ((DAT_3ffc6550 != '\0') && (param_1 != 0)) {
    uVar1 = 0;
    while (((uVar1 & 0xff) < param_1 && ((uVar1 & 0xff) < 3))) {
      uStack_38 = *(undefined4 *)(param_2 + uVar1 * 4);
      uStack_24 = 0;
      uStack_2c = 0;
      uStack_30 = 0;
      uStack_34 = 0;
      uStack_28 = 0;
      memw();
      memw();
      FUN_4011da90(uVar1,&uStack_38);
      uVar1 = uVar1 + 1;
    }
    for (; (param_1 & 0xff) < 3; param_1 = param_1 + 1) {
      FUN_4011da90(param_1,0);
    }
  }
  return;
}


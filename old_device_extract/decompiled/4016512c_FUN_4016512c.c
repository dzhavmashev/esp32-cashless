// Function : FUN_4016512c
// Address  : 0x4016512c
// Size     : 117 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4016512c(uint param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  param_1 = param_1 & 0xff;
  uVar2 = 0x102;
  if ((param_1 < 0x13) && (iVar4 = *(int *)(&DAT_3ffc7d14 + param_1 * 4), iVar4 != 0)) {
    uVar3 = (param_1 == 0x11 || param_1 == 0) ^ 1;
    if ((_DAT_3ffc7d10 >> uVar3 & 1) != 0) {
      uVar1 = *(undefined1 *)(uVar3 * 4 + 0x3ffca370);
      *(undefined1 *)(iVar4 + 8) = uVar1;
      *(undefined1 *)(iVar4 + 9) = uVar1;
      *(byte *)(iVar4 + 0xb) = *(byte *)(iVar4 + 0xb) | 3;
      memw();
      memw();
      return 0;
    }
    *(byte *)(iVar4 + 0xb) = *(byte *)(iVar4 + 0xb) & 0xfc;
    memw();
    uVar2 = 0;
  }
  memw();
  return uVar2;
}


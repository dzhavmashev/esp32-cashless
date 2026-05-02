// Function : FUN_40123aa8
// Address  : 0x40123aa8
// Size     : 151 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40123aa8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,0x60);
  iVar2 = 0x101;
  _DAT_3ffc87e8 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0x401239b4;
    puVar1[1] = &LAB_401238e8;
    puVar1[5] = &DAT_40103870;
    puVar1[2] = 0x40123a70;
    puVar1[3] = 0x4012398c;
    puVar1[4] = 0x40123948;
    puVar1[6] = &DAT_401045d4;
    puVar1[9] = &DAT_401258dc;
    puVar1[10] = 0x4012594c;
    puVar1[0xb] = FUN_40123888;
    puVar1[0xc] = 0x401238bc;
    puVar1[0xd] = 0x401856d8;
    puVar1[7] = 0x40123e10;
    puVar1[8] = 0x40123f80;
    puVar1[0xe] = 0x4010517c;
    puVar1[0xf] = &LAB_401238fc;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0x40104404;
    puVar1[0x15] = &DAT_401856f8;
    puVar1[0x17] = 0x40104644;
    memw();
    FUN_40123e04();
    iVar2 = FUN_4010538c(_DAT_3ffc87e8);
    if (iVar2 == 0) {
      FUN_4015a36c(_DAT_3ffc87e8);
    }
  }
  return iVar2;
}


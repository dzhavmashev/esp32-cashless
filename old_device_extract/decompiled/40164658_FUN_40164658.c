// Function : FUN_40164658
// Address  : 0x40164658
// Size     : 224 bytes


void FUN_40164658(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  
  if (1 < *(byte *)(param_1 + 0x82)) {
    if (param_2 == 2) {
      *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) | 0x80;
      memw();
      bVar1 = (byte)(1 << 0x20 - (0x20 - (param_3 & 0x1f)));
      *(byte *)(param_1 + 0x10) = bVar1 | *(byte *)(param_1 + 0x10);
      memw();
      if ((*(char *)(param_1 + 0xe) - 2U & 0xfd) == 0) {
        *(undefined1 *)(param_1 + (param_3 & 0xff) + 0x11) = 2;
        memw();
        *(byte *)(param_1 + 0x26) = bVar1 | *(byte *)(param_1 + 0x26);
        *(undefined1 *)(param_1 + 0xe) = 2;
        memw();
      }
      if ((0x10 < *(byte *)(param_1 + 0x1a)) || ((byte)(*(char *)(param_1 + 1) - 0x11U) < 0x6e)) {
        *(undefined1 *)(param_1 + 0x1a) = 0x21;
        memw();
        memw();
        return;
      }
      memw();
      FUN_40186c44(param_1,3);
      *(undefined1 *)(param_1 + 0xe) = 3;
      *(undefined1 *)(param_1 + 0x1a) = 0x21;
      memw();
      param_2 = 3;
      memw();
    }
    if ((param_2 & 0xfffffffd) == 1) {
      if (param_2 == 1) {
        *(byte *)(param_1 + 0x10) =
             ((byte)(1 << 0x20 - (0x20 - (param_3 & 0x1f))) ^ 0xff) & *(byte *)(param_1 + 0x10);
      }
      *(undefined1 *)(param_1 + (param_3 & 0xff) + 0x11) = 1;
      memw();
      if ((byte)(*(char *)(param_1 + 0xe) - 3U) < 2) {
        *(undefined1 *)(param_1 + 0xe) = 1;
        memw();
      }
    }
  }
  memw();
  return;
}


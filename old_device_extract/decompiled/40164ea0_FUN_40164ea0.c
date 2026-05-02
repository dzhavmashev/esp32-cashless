// Function : FUN_40164ea0
// Address  : 0x40164ea0
// Size     : 137 bytes


void FUN_40164ea0(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    bVar1 = *(byte *)(param_1 + 0xb);
    if ((((-1 < (char)bVar1) && (uVar2 = bVar1 & 1, (bVar1 & 1) == 0)) &&
        ((*(uint *)(param_1 + 0x18) & 0x8000) != 0)) &&
       ((*(char *)(param_1 + (*(uint *)(*(int *)(param_2 + 0x2c) + 4) & 0xf) + 0x11) == '\x01' &&
        ((int)(uint)*(byte *)(*(int *)(param_1 + 0x60) + 10) < (int)(DAT_3ffc06f5 - 1))))) {
      *(undefined1 *)(param_1 + 0xd) =
           *(undefined1 *)((DAT_3ffc06f5 - 2 & 0xff) * 0xc + *(int *)(param_1 + 0x70));
      memw();
      memw();
      FUN_40186c44(param_1,4);
      *(undefined1 *)(param_1 + 0xe) = 4;
      memw();
      memw();
      FUN_401641ec(param_1);
      do {
        if (((uint)*(byte *)(param_1 + 0x10) & 1 << ((byte)uVar2 & 0x1f)) != 0) {
          FUN_40164658(param_1,2,uVar2);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 != 8);
    }
  }
  return;
}


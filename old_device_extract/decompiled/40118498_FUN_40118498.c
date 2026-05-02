// Function : FUN_40118498
// Address  : 0x40118498
// Size     : 99 bytes


void FUN_40118498(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1;
  if (99 < param_2) {
    uVar2 = param_2 / 100;
  }
  uVar1 = (*(code *)&SUB_400842fc)();
  uVar1 = uVar1 % uVar2;
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  if ((*(char *)(param_1 + 0x19) == '\x02') ||
     ((*(char *)(param_1 + 0x19) == '\x01' &&
      ((*(ushort *)(param_1 + 0x1a) == 0 || ((uVar1 & 0xffff) < (uint)*(ushort *)(param_1 + 0x1a))))
      ))) {
    *(short *)(param_1 + 0x1a) = (short)uVar1;
    *(undefined1 *)(param_1 + 0x19) = 1;
    memw();
    if (DAT_3ffc6490 == '\0') {
      memw();
      FUN_40113258(100,&DAT_40118970);
      DAT_3ffc6490 = '\x01';
      memw();
    }
  }
  memw();
  return;
}


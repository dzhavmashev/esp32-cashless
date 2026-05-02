// Function : FUN_40164fe8
// Address  : 0x40164fe8
// Size     : 159 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40164fe8(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_3ffc7d58 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0x88);
  memw();
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0x88);
  iVar1 = _DAT_3ffc7d58;
  _DAT_3ffc7d5c = iVar2;
  if ((iVar2 != 0) && (_DAT_3ffc7d58 != 0)) {
    *(undefined1 **)(_DAT_3ffc7d58 + 0x60) = &DAT_3ffc0484;
    *(undefined4 *)(iVar1 + 0x70) = 0x3ffc0460;
    *(undefined1 **)(iVar1 + 100) = &DAT_3ffc0484;
    *(undefined1 **)(iVar1 + 0x68) = &DAT_3ffc0484;
    *(undefined4 *)(iVar1 + 0x6c) = 0x3ffc04fc;
    *(undefined1 *)(iVar1 + 0xb) = 0x80;
    *(undefined1 *)(iVar1 + 0x26) = 0;
    *(undefined1 *)(iVar1 + 0x83) = 0;
    *(undefined1 *)(iVar1 + 0x81) = 0;
    *(undefined1 **)(iVar2 + 0x60) = &DAT_3ffc0484;
    *(undefined4 *)(iVar2 + 0x70) = 0x3ffc0460;
    *(undefined1 **)(iVar2 + 100) = &DAT_3ffc0484;
    *(undefined1 **)(iVar2 + 0x68) = &DAT_3ffc0484;
    *(undefined4 *)(iVar2 + 0x6c) = 0x3ffc04fc;
    *(undefined1 *)(iVar2 + 0xb) = 0x80;
    *(undefined1 *)(iVar2 + 0x26) = 0;
    *(undefined1 *)(iVar2 + 0x83) = 0;
    *(undefined1 *)(iVar2 + 0x81) = 1;
    memw();
    memw();
    return 0;
  }
  memw();
  FUN_40147fe4(6,0x200,1,"lid ifx");
  return 0x101;
}


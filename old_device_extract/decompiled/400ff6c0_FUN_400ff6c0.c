// Function : FUN_400ff6c0
// Address  : 0x400ff6c0
// Size     : 173 bytes


uint FUN_400ff6c0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)**(undefined4 **)(&DAT_3f40e4e8 + param_1 * 4);
  memw();
  memw();
  memw();
  memw();
  uVar2 = *(uint *)(puVar4 + 0x60);
  memw();
  memw();
  memw();
  if ((uVar2 >> 2 & 0x7ff) < (uVar2 >> 0xd & 0x7ff)) {
    memw();
    uVar3 = uVar2 >> 0xd & 0x7ff;
    memw();
  }
  else {
    memw();
    memw();
    if ((uVar2 >> 2 & 0x7ff) <= (uVar2 >> 0xd & 0x7ff)) {
      if ((*(uint *)(puVar4 + 0x1c) & 0xff) == 0) {
        return 0xffffffff;
      }
      goto LAB_400ff718;
    }
    memw();
    uVar3 = (uVar2 >> 0xd & 0x7ff) + 0x80;
    memw();
  }
  if (uVar3 == (uVar2 >> 2 & 0x7ff)) {
    return 0xffffffff;
  }
LAB_400ff718:
  puVar1 = (uint *)&DAT_3ff40000;
  if ((puVar4 != &DAT_3ff40000) && (puVar1 = (uint *)&DAT_3ff50000, puVar4 != &DAT_3ff50000)) {
    puVar1 = (uint *)&DAT_3ff6e000;
  }
  memw();
  memw();
  return *puVar1 & 0xff;
}


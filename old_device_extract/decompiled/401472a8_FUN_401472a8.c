// Function : FUN_401472a8
// Address  : 0x401472a8
// Size     : 174 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_401472a8(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  if (*_DAT_3ffbfc54 == '\x01') {
    bVar1 = _DAT_3ffbfc54[0x9c];
  }
  else {
    bVar1 = _DAT_3ffbfc54[0x3fa];
  }
  pcVar4 = (code *)(uint)bVar1;
  if (_DAT_3ffc8874 != (undefined2 *)0x0) {
    *(bool *)((int)_DAT_3ffc8874 + 9) = pcVar4 == (code *)&DAT_00000004;
    memw();
    memw();
    return (ulonglong)(pcVar4 == (code *)&DAT_00000004) << 0x20;
  }
  puVar2 = (undefined2 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(0xd);
  uVar3 = 0x101;
  if (puVar2 != (undefined2 *)0x0) {
    FUN_4014c10c(puVar2 + 1,7,1,9);
    *(undefined1 *)(puVar2 + 5) = 2;
    *(undefined1 *)((int)puVar2 + 0xb) = 0x20;
    *(undefined1 *)(puVar2 + 6) = 0x21;
    *(bool *)((int)puVar2 + 9) = pcVar4 == (code *)&DAT_00000004;
    memw();
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    _DAT_3ffc8874 = puVar2;
    *puVar2 = 0xb;
    DAT_3ffc8a04 = 1;
    memw();
    pcVar4 = *(code **)(_DAT_3ffc1a34 + 0x58);
    memw();
    (*pcVar4)(_DAT_3ffc799c);
    uVar3 = 0;
  }
  return CONCAT44(pcVar4,uVar3);
}


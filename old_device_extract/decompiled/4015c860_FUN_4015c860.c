// Function : FUN_4015c860
// Address  : 0x4015c860
// Size     : 138 bytes


undefined4 FUN_4015c860(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = 0xff;
  uVar2 = (uint)DAT_3ffca0b6;
  if (uVar2 < 4) {
    if (uVar2 < 2) {
      puVar3 = &DAT_3ffc91f8 + (uVar2 + 0x3a8) * 4;
    }
    else {
      uVar5 = 0;
      piVar4 = (int *)&DAT_3ffca0a0;
      do {
        uVar6 = uVar5;
        if (*(char *)(*piVar4 + 0xab) == *(char *)(param_1 + 0xab)) break;
        uVar5 = uVar5 + 1 & 0xff;
        piVar4 = piVar4 + 1;
        uVar6 = uVar2;
      } while (uVar2 != uVar5);
      for (uVar5 = uVar2; uVar6 + 1 < uVar5; uVar5 = uVar5 - 1 & 0xff) {
        *(undefined4 *)((uVar5 + 0x3a8) * 4 + 0x3ffc9200) =
             *(undefined4 *)((uVar5 + 0x3a7) * 4 + 0x3ffc9200);
      }
      if (uVar2 == uVar6) {
        puVar3 = &DAT_3ffc91f8 + (uVar2 + 0x3a8) * 4;
        memw();
      }
      else {
        puVar3 = &DAT_3ffc91f8 + (uVar6 + 0x3a9) * 4;
      }
    }
    DAT_3ffca0b6 = DAT_3ffca0b6 + 1;
    *(int *)(puVar3 + 8) = param_1;
    uVar1 = 0;
    memw();
  }
  memw();
  return uVar1;
}


// Function : FUN_4015cd08
// Address  : 0x4015cd08
// Size     : 172 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015cd08(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  memw();
  FUN_40147fe4(1,4,4,0x3f434533,*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5),
               *(undefined1 *)(param_1 + 6),*(undefined1 *)(param_1 + 7),
               *(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
  if (param_1 == _DAT_3ffc7b08) {
    _DAT_3ffc7b08 = 0;
  }
  memw();
  uVar1 = 0;
  do {
    uVar3 = uVar1;
    uVar2 = uVar3 & 0xff;
    if (DAT_3ffca0b6 <= uVar2) {
      return;
    }
    uVar1 = uVar3 + 1;
  } while (param_1 != *(int *)((uVar3 + 1) * 4 + 0x3ffca09c));
  (*(code *)&SUB_4008b530)(param_1,0,0x3a8);
  *(undefined4 *)((uVar3 + 0x3a8) * 4 + 0x3ffc9200) = 0;
  DAT_3ffca0b6 = DAT_3ffca0b6 - 1;
  uVar1 = (uint)DAT_3ffca0b6;
  memw();
  memw();
  for (; uVar2 < uVar1; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined4 *)((uVar2 + 0x3a8) * 4 + 0x3ffc9200) =
         *(undefined4 *)((uVar2 + 0x3a9) * 4 + 0x3ffc9200);
  }
  memw();
  return;
}


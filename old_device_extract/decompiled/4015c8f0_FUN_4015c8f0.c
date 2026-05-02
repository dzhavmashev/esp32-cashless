// Function : FUN_4015c8f0
// Address  : 0x4015c8f0
// Size     : 75 bytes


void FUN_4015c8f0(void)

{
  int iVar1;
  uint uVar2;
  
  FUN_40147fe4(1,4,4,0x3f434565);
  for (uVar2 = 0; uVar2 < DAT_3ffca0b6; uVar2 = uVar2 + 1 & 0xff) {
    iVar1 = (uVar2 + 0x3a8) * 4;
    (*(code *)&SUB_4008b530)(*(undefined4 *)(iVar1 + 0x3ffc9200),0);
    *(undefined4 *)(iVar1 + 0x3ffc9200) = 0;
  }
  DAT_3ffca0b6 = 0;
  memw();
  memw();
  return;
}


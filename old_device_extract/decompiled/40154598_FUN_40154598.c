// Function : FUN_40154598
// Address  : 0x40154598
// Size     : 250 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40154598(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0xd4);
  if (iVar2 == 0) {
    FUN_40147fe4(1,0x4000,1,"");
    return 0x101;
  }
  if (param_1 == 0) {
    FUN_40147fe4(1,0x800,1,"",&UNK_3f423e3d,0x139);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined1 *)(param_1 + 0x1aa) = 2;
  *(undefined1 *)(param_1 + 0x1ab) = 0x20;
  *(undefined1 *)(param_1 + 0x1ac) = 0x21;
  memw();
  if (param_2 == 1) {
    memw();
    iVar2 = (*(code *)&SUB_4008b3d0)(iVar2,&UNK_3f423f24);
    uVar3 = 0xf;
  }
  else {
    iVar2 = (*(code *)&SUB_4008b3d0)(iVar2,&UNK_3f423e50,0xd4);
    uVar3 = 0xfff;
  }
  if (*(uint *)(param_1 + 0x1b4) != 0) {
    uVar3 = uVar3 & *(uint *)(param_1 + 0x1b4);
  }
  *(undefined1 *)(param_1 + 0x169) = 0;
  memw();
  memw();
  for (; uVar3 != 0;
      uVar3 = uVar3 & (1 << 0x20 - (0x20 - (-LZCOUNT(-uVar3 & uVar3) + 0x1fU & 0x1f)) ^ 0xffffffffU)
      ) {
    bVar1 = *(byte *)(param_1 + 0x169);
    *(byte *)(param_1 + 0x169) = bVar1 + 1;
    memw();
    *(undefined1 *)(param_1 + (uint)bVar1 + 0x16a) =
         *(undefined1 *)(iVar2 + (-LZCOUNT(-uVar3 & uVar3) + 0x20) * 0x10 + 0xe);
    memw();
  }
  if (param_1 == _DAT_3ffc8804) {
    DAT_3ffc8a04 = 1;
    memw();
  }
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar2);
  return 0;
}


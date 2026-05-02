// Function : FUN_40168f80
// Address  : 0x40168f80
// Size     : 162 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40168f80(void)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = 0;
  sVar2 = (short)DAT_3ffca53c;
  puVar1 = (ushort *)0x3ffc3898;
  puVar4 = &DAT_3ffca560;
  iVar3 = 0x3ffca55a;
  while( true ) {
    sVar6 = 0;
    if ((uVar5 & 1) != 0) {
      sVar6 = 6;
    }
    sVar7 = 0;
    if ((_DAT_3ffc073e & 1) != 0) {
      sVar7 = 6;
    }
    iVar8 = (int)(short)(((((ushort)(uVar5 >> 6) & 0xff) + sVar6 & 0xff) -
                         ((_DAT_3ffc073e >> 6 & 0xff) + sVar7 & 0xff)) * 4 + sVar2 + 0x2b);
    iVar9 = 0;
    if ((-1 < iVar8) && (iVar9 = 0x78, iVar8 < 0x79)) {
      iVar9 = iVar8;
    }
    FUN_4016bffc(uVar5,puVar4,iVar3,0x20,iVar9,1);
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 8;
    iVar3 = iVar3 + 2;
    if (puVar1 == (ushort *)0x3ffc389e) break;
    uVar5 = (uint)*puVar1;
  }
  _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x800;
  return;
}


// Function : FUN_401547bc
// Address  : 0x401547bc
// Size     : 126 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_401547bc(int param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  
  uVar2 = *(ushort *)(param_1 + 0x26);
  pbVar6 = (byte *)((uVar2 >> 3 & 0x7ff) + 0x3ffc899f);
  bVar1 = *pbVar6;
  bVar3 = ((int)(uint)bVar1 >> (uVar2 & 7) & 1U) != param_2;
  if (bVar3) {
    iVar5 = *(int *)(_DAT_3ffc8804 + 0xec);
    bVar4 = (byte)(1 << 0x20 - (0x20 - (uVar2 & 7)));
    if (param_2 == 0) {
      *pbVar6 = (bVar4 ^ 0xff) & bVar1;
      memw();
      if (iVar5 != param_1) goto LAB_40154834;
      DAT_3ffc899e = DAT_3ffc899e & 0xfe;
    }
    else {
      *pbVar6 = bVar4 | bVar1;
      memw();
      if (iVar5 != param_1) goto LAB_40154834;
      DAT_3ffc899e = DAT_3ffc899e | 1;
      memw();
    }
    memw();
  }
LAB_40154834:
  memw();
  return bVar3;
}


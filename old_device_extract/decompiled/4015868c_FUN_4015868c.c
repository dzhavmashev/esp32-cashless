// Function : FUN_4015868c
// Address  : 0x4015868c
// Size     : 156 bytes


undefined4 FUN_4015868c(int param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar7 = 0xffffffff;
  if (0x17 < *(byte *)(param_2 + 1)) {
    bVar2 = *(byte *)(param_2 + 8);
    bVar6 = bVar2 & 0xf;
    if ((*(char *)(param_1 + 0x25) == '\0') || (uVar7 = 0, *(byte *)(param_1 + 0x87) != bVar6)) {
      *(byte *)(param_1 + 0x87) = bVar6;
      pbVar4 = (byte *)(param_2 + 10);
      *(byte *)(param_1 + 0x10) = bVar2 >> 7;
      iVar5 = 0;
      *(undefined1 *)(param_1 + 0x25) = 1;
      memw();
      do {
        memw();
        uVar3 = FUN_40158644(iVar5);
        iVar8 = param_1 + (uVar3 & 0xffff) * 7;
        iVar5 = iVar5 + 1;
        *(char *)(iVar8 + 0x89) = (char)((int)(*pbVar4 & 0x10) >> 4);
        memw();
        *(byte *)(iVar8 + 0x8a) = *pbVar4 & 0xf;
        memw();
        *(byte *)(iVar8 + 0x8b) = pbVar4[1] & 0xf;
        memw();
        *(byte *)(iVar8 + 0x8c) = pbVar4[1] >> 4;
        memw();
        pbVar1 = pbVar4 + 2;
        pbVar4 = pbVar4 + 4;
        *(byte *)(iVar8 + 0x8d) = *pbVar1;
        memw();
      } while (iVar5 != 4);
      uVar7 = 1;
    }
  }
  memw();
  return uVar7;
}


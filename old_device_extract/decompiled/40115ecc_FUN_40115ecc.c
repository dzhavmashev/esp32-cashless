// Function : FUN_40115ecc
// Address  : 0x40115ecc
// Size     : 406 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40115ecc(int param_1,undefined4 param_2)

{
  short sVar1;
  byte *pbVar2;
  undefined1 uVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined4 uVar11;
  char *pcVar12;
  
  pbVar2 = _DAT_3ffc83c0;
  uVar8 = (*_DAT_3ffc83c0 & 0xf) * 4;
  if (((((uVar8 < 0x14) || (*(ushort *)(param_1 + 10) < 4)) || (**(char **)(param_1 + 4) != '\b'))
      || (((_DAT_3ffc83e4 & 0xf0) == 0xe0 ||
          (iVar6 = FUN_4018549c(_DAT_3ffc83e4,_DAT_3ffc83b8), iVar6 != 0)))) ||
     ((*(ushort *)(param_1 + 8) < 8 || (iVar6 = FUN_4011dc78(param_1), iVar6 != 0))))
  goto LAB_40115f14;
  iVar7 = uVar8 + 0xe;
  iVar6 = FUN_4010ba7c(param_1,iVar7);
  if (iVar6 == 0) {
    iVar6 = FUN_4010ba9c(param_1,iVar7);
    if (iVar6 != 0) {
      pcVar12 = "/icmp.c";
      uVar11 = 199;
LAB_40115f73:
      (*(code *)&SUB_40094c54)("failed\n",uVar11,"esponse",pcVar12);
LAB_40115f7c:
      cVar4 = FUN_4010bf9c(iVar7,param_1);
      if (cVar4 != '\0') goto LAB_40115f4a;
      FUN_4010bb10(param_1);
      param_1 = iVar7;
    }
    puVar9 = *(undefined1 **)(param_1 + 4);
    iVar6 = FUN_4010ba7c(param_1,uVar8);
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 4);
      *(undefined1 *)(iVar6 + 0xc) = DAT_3ffc83e4;
      memw();
      *(undefined1 *)(iVar6 + 0xd) = DAT_3ffc83e5;
      memw();
      *(undefined1 *)(iVar6 + 0xe) = DAT_3ffc83e6;
      memw();
      *(undefined1 *)(iVar6 + 0xf) = DAT_3ffc83e7;
      memw();
      *(undefined1 *)(iVar6 + 0x10) = DAT_3ffc83cc;
      memw();
      *(undefined1 *)(iVar6 + 0x11) = DAT_3ffc83cd;
      uVar3 = DAT_3ffc83cf;
      memw();
      *(undefined1 *)(iVar6 + 0x12) = DAT_3ffc83ce;
      *(undefined1 *)(iVar6 + 0x13) = uVar3;
      memw();
      sVar1 = 8;
      *puVar9 = 0;
      memw();
      if (0xfff7 < *(ushort *)(puVar9 + 2)) {
        sVar1 = 9;
      }
      *(ushort *)(puVar9 + 2) = *(ushort *)(puVar9 + 2) + sVar1;
      *(undefined1 *)(iVar6 + 8) = 0x40;
      *(undefined1 *)(iVar6 + 10) = 0;
      *(undefined1 *)(iVar6 + 0xb) = 0;
      memw();
      memw();
      uVar5 = FUN_4011dc60(iVar6,uVar8);
      *(char *)(iVar6 + 10) = (char)uVar5;
      *(char *)(iVar6 + 0xb) = (char)((ushort)uVar5 >> 8);
      memw();
      memw();
      FUN_40116d00(param_1,&DAT_3ffc83e4,0,0x40,0,1,param_2);
    }
  }
  else {
    uVar10 = *(ushort *)(param_1 + 8) + uVar8 & 0xffff;
    if ((uVar10 < *(ushort *)(param_1 + 8)) || (iVar7 = FUN_4010bbc4(0xe,uVar10,0x280), iVar7 == 0))
    goto LAB_40115f14;
    if (uVar8 + 8 <= (uint)*(ushort *)(iVar7 + 10)) {
      (*(code *)&SUB_4008b3d0)(*(undefined4 *)(iVar7 + 4),pbVar2,uVar8);
      iVar6 = FUN_4010ba9c(iVar7,uVar8);
      if (iVar6 != 0) {
        pcVar12 = "tharp_q";
        uVar11 = 0xb6;
        goto LAB_40115f73;
      }
      goto LAB_40115f7c;
    }
LAB_40115f4a:
    FUN_4010bb10(iVar7);
  }
LAB_40115f14:
  FUN_4010bb10(param_1);
  return;
}


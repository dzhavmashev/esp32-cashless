// Function : FUN_4014b1ec
// Address  : 0x4014b1ec
// Size     : 259 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014b1ec(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  *param_2 = 600000;
  uVar2 = 0xffffffff;
  if (param_1 != 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 0x288);
    memw();
    for (; uVar2 = 0, uVar3 != 0;
        uVar3 = uVar3 & (uint)(0xfffffffefffffffe >>
                              0x20 - (-LZCOUNT(-uVar3 & uVar3) + 0x1fU & 0x1f))) {
      iVar6 = *(int *)((-LZCOUNT(-uVar3 & uVar3) + 0xb7) * 4 + param_1 + 8);
      if (iVar6 == 0) {
        FUN_40147fe4(1,0x400,1,"");
        iVar4 = 600000;
      }
      else {
        iVar8 = (int)*(short *)(iVar6 + 8);
        iVar4 = 600000;
        if (0 < iVar8) {
          if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
            memw();
            iVar1 = _DAT_3ff73c00 + _DAT_3ffc1a30;
          }
          else {
            memw();
            iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
          }
          uVar5 = (uint)*(byte *)(iVar6 + 0xe);
          iVar4 = 600000;
          do {
            do {
              uVar5 = uVar5 - 1 & 0xff;
              if (uVar5 == 0) goto LAB_4014b2d9;
              iVar7 = *(int *)(uVar5 * 4 + *(int *)(iVar6 + 0x18));
            } while (iVar7 == 0);
            iVar7 = (*(int *)(*(int *)(iVar7 + 0x2c) + 4) + 300000) - iVar1;
            if (iVar7 < 1) {
              FUN_40189f58(param_1,iVar6,*(ushort *)(iVar6 + 0xc) + 1 + uVar5 & 0xfff);
              break;
            }
            iVar8 = iVar8 + -1;
            iVar4 = (uint)(iVar4 < iVar7) * iVar4 + (uint)(iVar4 >= iVar7) * iVar7;
          } while (iVar8 != 0);
        }
      }
LAB_4014b2d9:
      if (iVar4 < *param_2) {
        *param_2 = iVar4;
      }
    }
  }
  memw();
  return uVar2;
}


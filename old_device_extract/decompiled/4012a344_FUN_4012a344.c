// Function : FUN_4012a344
// Address  : 0x4012a344
// Size     : 265 bytes


int FUN_4012a344(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = param_1[0x21];
  cVar1 = *(char *)(*param_1 + 5);
  uVar2 = 0xc;
  if (cVar1 != '\x01') {
    uVar2 = 4;
  }
  if (uVar2 <= uVar7) {
    pcVar3 = (char *)param_1[0x1e];
    uVar2 = ((uint)(byte)pcVar3[1] << 0x10 | (uint)(byte)pcVar3[2] << 8 | (uint)(byte)pcVar3[3]) +
            uVar2;
    param_1[0x2a] = uVar2;
    if (cVar1 != '\x01') {
      if (uVar2 <= uVar7) {
        return 0;
      }
      return -0x7080;
    }
    uVar5 = (uint)(byte)pcVar3[1] << 0x10 | (uint)(byte)pcVar3[2] << 8 | (uint)(byte)pcVar3[3];
    uVar2 = (uint)(byte)pcVar3[6] << 0x10 | (uint)(byte)pcVar3[7] << 8 | (uint)(byte)pcVar3[8];
    uVar4 = (uint)(byte)pcVar3[9] << 0x10 | (uint)(byte)pcVar3[10] << 8 | (uint)(byte)pcVar3[0xb];
    if (((uVar2 <= uVar5) && (uVar4 <= uVar5 - uVar2)) && (uVar4 + 0xc <= uVar7)) {
      iVar6 = param_1[0x11];
      if (iVar6 != 0) {
        uVar2 = (*(ushort *)(pcVar3 + 4) & 0xff) << 8 | (uint)(*(ushort *)(pcVar3 + 4) >> 8);
        if (param_1[1] == 0x10) {
          if (*pcVar3 != '\x01') goto LAB_4012a416;
        }
        else if (*(uint *)(iVar6 + 0x23c) != uVar2) {
LAB_4012a416:
          if (*(uint *)(iVar6 + 0x23c) < uVar2) {
            return -0x6480;
          }
          if (((*(int *)(iVar6 + 600) - 1U == uVar2) && (*pcVar3 != '\x03')) &&
             (iVar6 = FUN_40129fc8(), iVar6 != 0)) {
            return iVar6;
          }
          return -0x6580;
        }
      }
      memw();
      iVar6 = FUN_40129108();
      if (iVar6 != 1) {
        return 0;
      }
      return -0x6480;
    }
  }
  return -0x7200;
}


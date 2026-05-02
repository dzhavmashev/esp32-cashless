// Function : FUN_4016d398
// Address  : 0x4016d398
// Size     : 583 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016d398(undefined1 param_1,int param_2,uint param_3,char param_4,char *param_5,
                 undefined2 param_6,char param_7,char param_8)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iStack_4c;
  uint uStack_44;
  
  uVar8 = (param_3 & 0xff) - 1;
  iStack_4c = (int)(char)uVar8;
  if (-1 < iStack_4c) {
    iVar10 = 0;
    uStack_44 = uVar8;
    do {
      uStack_44 = uStack_44 & 0xff;
      bVar1 = *(byte *)(param_2 + iStack_4c);
      if (iStack_4c < (int)uVar8) {
        iVar10 = (int)(short)(((ushort)((byte *)(param_2 + iStack_4c))[1] - (ushort)bVar1) +
                             (short)iVar10);
      }
      iVar11 = 0;
      uVar12 = 2;
      do {
        cVar7 = param_7 + (char)iVar10;
        cVar7 = (-1 < cVar7) * cVar7;
        cVar7 = (cVar7 < 'd') * cVar7 + (cVar7 >= 'd') * 'd';
        iVar9 = (int)cVar7;
        (**(code **)(_DAT_3ffc7e64 + 0x44))(1,param_1,iVar9,0,0);
        (*(code *)&SUB_40008534)(2);
        sVar2 = (**(code **)(_DAT_3ffc7e64 + 0x178))(param_6);
        sVar3 = (**(code **)(_DAT_3ffc7e64 + 0x178))(param_6);
        iVar4 = (short)(sVar2 + sVar3) + 4 >> 3;
        if (iVar4 < 0) {
          sVar2 = 0;
          iVar4 = 0;
        }
        else {
          sVar2 = (short)iVar4;
          iVar4 = (int)sVar2;
        }
        uVar5 = (uint)(short)(sVar2 - (ushort)bVar1);
        if ((int)uVar5 < 0x19) {
          if ((int)uVar5 < -0x18) {
            uVar5 = 0xffffffe8;
            goto LAB_4016d5da;
          }
          if (param_8 != '\0') goto LAB_4016d4db;
LAB_4016d4f7:
          if ((uVar5 == 0) && ((((int)(char)iVar11 >> 7) - iVar11 & 0x80U) != 0)) break;
        }
        else {
          uVar5 = 0x18;
LAB_4016d5da:
          if (param_8 != '\0') {
LAB_4016d4db:
            FUN_40168620(0x3ffc3a18,iVar11,iVar4,bVar1,uVar5,iVar10,iVar9);
            goto LAB_4016d4f7;
          }
        }
        if ((uVar5 == 0xffffffff && uVar12 == 1) || (uVar12 == 0)) break;
        if ((iVar9 == 0) && ((int)uVar5 < 0)) {
          cVar7 = '\0';
          break;
        }
        if ((iVar9 == 100) && ((((int)uVar5 >> 0xf) - uVar5 & 0x8000) != 0)) {
          cVar7 = 'd';
          break;
        }
        sVar2 = (short)uVar5 + (short)iVar10;
        if (4 < ((uVar5 & 0xffff) + 2 & 0xffff)) {
          sVar2 = sVar2 - (short)((int)uVar5 >> 2);
        }
        iVar11 = iVar11 + 1;
        iVar10 = (int)sVar2;
        uVar12 = uVar5;
      } while (iVar11 != 10);
      uStack_44 = uStack_44 - 1;
      cVar7 = cVar7 - param_4;
      pcVar6 = param_5 + iStack_4c;
      iStack_4c = (int)(char)uStack_44;
      *pcVar6 = (cVar7 < -0x18) * -0x18 + (cVar7 >= -0x18) * cVar7;
    } while (iStack_4c != -1);
  }
  if (0x32 < (int)param_5[(param_3 & 0xff) - 1] - (int)*param_5) {
    *param_5 = param_5[(param_3 & 0xff) - 1] + -0x32;
    memw();
  }
  (**(code **)(_DAT_3ffc7e64 + 0x4c))(1);
  return;
}


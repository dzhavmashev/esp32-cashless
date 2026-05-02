// Function : FUN_4015d158
// Address  : 0x4015d158
// Size     : 677 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4015d158(undefined1 *param_1,int param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iStack_40;
  
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar1 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  if ((*(char *)(_DAT_3ffbfc54 + 0x35e) <= param_2) && (*(byte *)(_DAT_3ffbfc54 + 0x35f) <= param_3)
     ) {
    if ((param_3 < 6) && (DAT_3ffc8a6a != '\0')) {
      FUN_40147fe4(1,4,4,0x3f43469e);
    }
    else {
      iVar2 = FUN_4015c48c(param_1);
      iVar5 = _DAT_3ffc94a8;
      if (iVar2 == 0) {
        if ((((*(int *)(_DAT_3ffca40c + 4) == 0) || (*(int *)(_DAT_3ffca40c + 8) == 0)) ||
            (*(int *)(_DAT_3ffca40c + 8) == 3)) &&
           (((_DAT_3ffc89a8 == 0 && (pcVar3 = (char *)FUN_4015a07c(), *pcVar3 == '\0')) &&
            (param_3 != 0)))) {
          memw();
          FUN_40147fe4(1,4,4,0x3f43463c);
          DAT_3ffc7aed = 1;
          memw();
          memw();
          return 0;
        }
        if ((_DAT_3ffc89a8 == 0) || (param_3 != 0)) {
          uVar7 = iVar1 - iVar5;
          iVar2 = 0;
          iVar5 = 0x3ffc9200;
          iStack_40 = 0x7fffffff;
          iVar1 = 0x3ffc9200;
          do {
            if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0))
            {
              memw();
              iVar4 = _DAT_3ff73c00 + _DAT_3ffc1a30;
            }
            else {
              memw();
              iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
            }
            uVar6 = iVar4 - *(int *)(iVar5 + 0x2a8);
            iVar4 = iVar5;
            if ((*(int *)(&DAT_3ffc9204 + iVar2 * 0x3a8) == 0) &&
               (uVar8 = uVar7, *(short *)(&DAT_3ffc9208 + iVar2 * 0x3a8) == 0)) break;
            if (_DAT_3ffca0b8 != iVar5) {
              uVar8 = uVar6;
              if (29999999 < uVar6) break;
              if (*(char *)(_DAT_3ffbfc54 + 0x35d) == '\0') {
                memw();
                iVar4 = FUN_4015b5d8(iVar5);
                if (iVar4 < iStack_40) {
                  memw();
                  iStack_40 = iVar4;
LAB_4015d387:
                  iVar1 = iVar5;
                  uVar7 = uVar6;
                }
              }
              else if (*(byte *)(iVar5 + 0x28b) < *(byte *)(iVar1 + 0x28b)) goto LAB_4015d387;
            }
            iVar2 = iVar2 + 1;
            iVar5 = iVar5 + 0x3a8;
            iVar4 = iVar1;
            uVar8 = uVar7;
          } while (iVar2 != 4);
          if ((*(int *)(iVar4 + 4) != 0) || (*(short *)(iVar4 + 8) != 0)) {
            if (((uVar8 < 30000000) &&
                ((param_2 <= *(char *)(iVar4 + 0xa6) || (*(char *)(_DAT_3ffbfc54 + 0x35d) != '\0')))
                ) && ((param_3 <= *(byte *)(iVar4 + 0x28b) ||
                      (*(char *)(_DAT_3ffbfc54 + 0x35d) == '\0')))) {
              if (*(char *)(_DAT_3ffbfc54 + 0x92) == '\0') {
                return 0;
              }
              iVar1 = (*(code *)&SUB_4008b33c)(_DAT_3ffbfc54 + 0x93,param_1,6);
              if (iVar1 != 0) {
                return 0;
              }
            }
            FUN_4015cd08(iVar4);
          }
          return iVar4;
        }
        FUN_40147fe4(1,4,4,0x3f434617);
        DAT_3ffc7aed = 1;
        memw();
        memw();
      }
      else {
        memw();
        FUN_40147fe4(1,4,4,0x3f434668,*param_1,param_1[1],param_1[2],param_1[3],param_1[4],
                     param_1[5]);
        DAT_3ffc7aec = 1;
        memw();
        memw();
      }
    }
  }
  return 0;
}


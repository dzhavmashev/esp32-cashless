// Function : FUN_4014de24
// Address  : 0x4014de24
// Size     : 431 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014de24(char param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_30 [12];
  
  iVar2 = _DAT_3ffc8804;
  iVar6 = _DAT_3ffc8800;
  iVar5 = _DAT_3ffbfc54;
  local_30[0] = param_2;
  if (param_1 == '\0') {
    if (*(byte *)(_DAT_3ffbfc54 + 0x9d) != param_2) {
      *(char *)(_DAT_3ffbfc54 + 0x9d) = (char)param_2;
      memw();
      memw();
      iVar5 = FUN_40150e8c(0xb,param_2 & 0xff,DAT_3ffc8a05 == '\0');
      if (iVar5 != 0) {
        return iVar5;
      }
      if ((iVar6 != 0) && (*(char *)(_DAT_3ffbfc54 + 0x9c) == '\x03')) {
        FUN_4014a9bc(iVar6);
      }
      goto LAB_4014dfc6;
    }
    iVar5 = FUN_40151060(0xb,local_30);
    if (iVar5 == 0) goto LAB_4014dfc6;
    *(char *)(_DAT_3ffbfc54 + 0x9d) = (char)local_30[0];
    memw();
    memw();
    iVar5 = FUN_40150e8c(0xb,local_30[0],DAT_3ffc8a05 == '\0');
  }
  else {
    if (param_1 != '\x01') goto LAB_4014dfc6;
    if (*(byte *)(_DAT_3ffbfc54 + 0x3fb) == param_2) {
      iVar6 = FUN_40151060(0x20,local_30);
      iVar5 = _DAT_3ffbfc54;
      if (iVar6 == 0) goto LAB_4014dfc6;
      *(char *)(_DAT_3ffbfc54 + 0x3fb) = (char)local_30[0];
      memw();
      uVar7 = local_30[0];
      if ((iVar2 != 0) &&
         (iVar5 = FUN_40150e8c(0x21,*(undefined1 *)(iVar5 + 0x3fc),DAT_3ffc8a05 == '\0'),
         uVar7 = local_30[0], iVar5 != 0)) {
        return iVar5;
      }
    }
    else {
      *(char *)(_DAT_3ffbfc54 + 0x3fb) = (char)param_2;
      memw();
      if (iVar2 != 0) {
        if (*(char *)(iVar5 + 0x3fa) == '\x03') {
          FUN_4014a9bc(iVar2);
        }
        if (local_30[0] == 2) {
          if (iVar6 != 0) {
            cVar1 = *(char *)(iVar6 + 0x157);
            if (cVar1 == '\x01') {
              bVar3 = *(char *)(iVar6 + 0x156) - 1;
            }
            else {
              if (cVar1 != '\x02') goto LAB_4014defd;
              bVar3 = *(char *)(iVar6 + 0x156) - 5;
            }
            if (bVar3 < 9) {
              *(char *)(iVar2 + 0x157) = cVar1;
              memw();
              memw();
              goto LAB_4014df19;
            }
          }
LAB_4014defd:
          if (*(byte *)(iVar2 + 0x156) < 5) {
            uVar4 = 1;
          }
          else {
            uVar4 = 2;
          }
LAB_4014df13:
          *(undefined1 *)(iVar2 + 0x157) = uVar4;
          memw();
        }
        else if (local_30[0] == 1) {
          uVar4 = 0;
          goto LAB_4014df13;
        }
LAB_4014df19:
        uVar4 = *(undefined1 *)(iVar2 + 0x157);
        *(undefined1 *)(_DAT_3ffbfc54 + 0x3fc) = uVar4;
        memw();
        memw();
        iVar5 = FUN_40150e8c(0x21,uVar4,DAT_3ffc8a05 == '\0');
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      memw();
      uVar7 = (uint)*(byte *)(_DAT_3ffbfc54 + 0x3fb);
    }
    memw();
    iVar5 = FUN_40150e8c(0x20,uVar7,DAT_3ffc8a05 == '\0');
  }
  if (iVar5 != 0) {
    return iVar5;
  }
LAB_4014dfc6:
  DAT_3ffc8a04 = 1;
  memw();
  memw();
  iVar5 = FUN_40150e38();
  return iVar5;
}


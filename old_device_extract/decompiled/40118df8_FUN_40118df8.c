// Function : FUN_40118df8
// Address  : 0x40118df8
// Size     : 228 bytes


char FUN_40118df8(int param_1)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  int *piVar8;
  
  piVar8 = (int *)&DAT_3ffc846c;
  cVar5 = '\0';
  cVar4 = -1;
  do {
    iVar7 = *piVar8;
    if ((iVar7 != 0) && (iVar2 = *(int *)(iVar7 + 0x14), iVar2 != 0)) {
      if (param_1 == 0) {
        bVar1 = false;
        if ((*(byte *)(iVar2 + 0xeb) & 1) != 0) {
          bVar1 = (bool)(*(byte *)(iVar2 + 0xeb) >> 2 & 1);
        }
      }
      else {
        bVar1 = iVar2 == param_1;
      }
      if ((bVar1 != false) && (*(char *)(iVar7 + 0x24) != '\x01')) {
        if (*(char *)(iVar7 + 0x24) == '\x02') goto LAB_40118ea5;
        if (cVar4 == -1) {
          cVar4 = cVar5;
        }
      }
    }
    cVar5 = cVar5 + '\x01';
    piVar8 = piVar8 + 3;
  } while (cVar5 != '\x03');
  cVar5 = cVar4;
  if (cVar4 == -1) {
    if (param_1 == 0) {
      DAT_3ffc6491 = DAT_3ffc6491 + '\x01';
      if (DAT_3ffc6491 < '\x03') {
        memw();
      }
      else {
        DAT_3ffc6491 = '\0';
        memw();
        memw();
      }
    }
    cVar6 = '\x03';
    cVar3 = DAT_3ffc6491;
    do {
      cVar5 = cVar3;
      if ((*(int *)(&DAT_3ffc846c + cVar5 * 0xc) != 0) &&
         (iVar7 = *(int *)(*(int *)(&DAT_3ffc846c + cVar5 * 0xc) + 0x14), iVar7 != 0)) {
        if (param_1 == 0) {
          bVar1 = false;
          if ((*(byte *)(iVar7 + 0xeb) & 1) != 0) {
            bVar1 = (bool)(*(byte *)(iVar7 + 0xeb) >> 2 & 1);
          }
        }
        else {
          bVar1 = param_1 == iVar7;
        }
        if (bVar1 != false) break;
      }
      cVar3 = cVar5 + '\x01';
      if ('\x02' < cVar3) {
        cVar3 = '\0';
      }
      cVar6 = cVar6 + -1;
      cVar5 = cVar4;
    } while (cVar6 != '\0');
  }
LAB_40118ea5:
  memw();
  return cVar5;
}


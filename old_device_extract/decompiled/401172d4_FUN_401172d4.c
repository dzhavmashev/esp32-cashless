// Function : FUN_401172d4
// Address  : 0x401172d4
// Size     : 545 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_401172d4(uint *param_1,uint *param_2)

{
  byte bVar1;
  int *piVar2;
  byte bVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  
  if ((_DAT_3ffc83fc == (int *)0x0) || (*_DAT_3ffc83fc != 0)) {
    piVar2 = _DAT_3ffc83fc;
    if ((char)param_2[4] != '\0') {
      while( true ) {
        if (piVar2 == (int *)0x0) {
          return (int *)0x0;
        }
        if ((((char)param_2[4] == (char)(*(char *)((int)piVar2 + 0xee) + '\x01')) &&
            ((*(byte *)((int)piVar2 + 0xeb) & 1) != 0)) &&
           ((*(byte *)((int)piVar2 + 0xeb) & 4) != 0)) break;
        piVar2 = (int *)*piVar2;
      }
      return piVar2;
    }
    uVar6 = *param_2;
    if (((((uVar6 & 0xc0ff) == 0x80fe) || (((uVar6 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) ||
        ((*param_1 & 0xc0ff) == 0x80fe)) ||
       (((*param_1 == 0 && (param_1[1] == 0)) && ((param_1[2] == 0 && (param_1[3] == 0x1000000))))))
    {
      if ((char)param_1[4] == '\0') {
        for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          if ((*(byte *)((int)piVar2 + 0xeb) & 5) == 5) {
            puVar4 = (uint *)(piVar2 + 0x13);
            puVar5 = (uint *)(piVar2 + 0x25);
            do {
              if ((((*puVar5 & 0x10) != 0) && (*param_1 == *puVar4)) &&
                 ((param_1[1] == puVar4[1] &&
                  ((param_1[2] == puVar4[2] && (param_1[3] == puVar4[3])))))) {
                return piVar2;
              }
              puVar4 = puVar4 + 6;
              puVar5 = (uint *)((int)puVar5 + 1);
            } while (puVar4 != (uint *)(piVar2 + 0x25));
          }
        }
      }
      else {
        for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          if ((((*(byte *)((int)piVar2 + 0xeb) & 1) != 0) &&
              ((*(byte *)((int)piVar2 + 0xeb) & 4) != 0)) &&
             ((char)param_1[4] == (char)(*(char *)((int)piVar2 + 0xee) + '\x01'))) {
            return piVar2;
          }
        }
      }
      if ((uVar6 & 0xff) == 0xff) {
        return _DAT_3ffc8400;
      }
      if (*param_1 != 0) {
        return (int *)0x0;
      }
      if (param_1[1] != 0) {
        return (int *)0x0;
      }
      if (param_1[2] != 0) {
        return (int *)0x0;
      }
      if (param_1[3] != 0) {
        return (int *)0x0;
      }
      return _DAT_3ffc8400;
    }
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if ((*(byte *)((int)piVar2 + 0xeb) & 5) == 5) {
        pbVar7 = (byte *)(piVar2 + 0x25);
        puVar5 = (uint *)(piVar2 + 0x13);
        do {
          if (((((*pbVar7 & 0x10) != 0) && (uVar6 == *puVar5)) && (param_2[1] == puVar5[1])) &&
             ((char)puVar5[4] == '\0')) {
            if (*(int *)((int)piVar2 * -3 + -0x1b8 + (int)pbVar7 * 4) == 0) {
              return piVar2;
            }
            if ((param_2[2] == puVar5[2]) && (param_2[3] == puVar5[3])) {
              return piVar2;
            }
          }
          pbVar7 = pbVar7 + 1;
          puVar5 = puVar5 + 6;
        } while (pbVar7 != (byte *)((int)piVar2 + 0x97));
      }
    }
    memw();
    piVar2 = (int *)FUN_4011a36c();
    if (piVar2 != (int *)0x0) {
      return piVar2;
    }
    piVar2 = _DAT_3ffc83fc;
    if (((*param_1 != 0) || (param_1[1] != 0)) || ((param_1[2] != 0 || (param_1[3] != 0)))) {
      for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        if ((*(byte *)((int)piVar2 + 0xeb) & 5) == 5) {
          puVar4 = (uint *)(piVar2 + 0x13);
          puVar5 = (uint *)(piVar2 + 0x25);
          do {
            if ((((((*puVar5 & 0x10) != 0) && (*param_1 == *puVar4)) && (param_1[1] == puVar4[1]))
                && ((param_1[2] == puVar4[2] && (param_1[3] == puVar4[3])))) &&
               ((byte)param_1[4] == (byte)puVar4[4])) {
              return piVar2;
            }
            puVar4 = puVar4 + 6;
            puVar5 = (uint *)((int)puVar5 + 1);
          } while ((uint *)(piVar2 + 0x25) != puVar4);
        }
      }
    }
    if (_DAT_3ffc8400 == (int *)0x0) {
      return (int *)0x0;
    }
    bVar3 = 5;
    bVar1 = *(byte *)((int)_DAT_3ffc8400 + 0xeb) & 5;
    piVar2 = _DAT_3ffc8400;
  }
  else {
    if ((*(byte *)((int)_DAT_3ffc83fc + 0xeb) & 5) != 5) {
      return (int *)0x0;
    }
    bVar3 = (byte)param_2[4];
    if (bVar3 == 0) {
      return _DAT_3ffc83fc;
    }
    bVar1 = *(char *)((int)_DAT_3ffc83fc + 0xee) + 1;
    piVar2 = _DAT_3ffc83fc;
  }
  if (bVar1 != bVar3) {
    return (int *)0x0;
  }
  return piVar2;
}


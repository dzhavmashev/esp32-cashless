// Function : FUN_4012a454
// Address  : 0x4012a454
// Size     : 216 bytes


int FUN_4012a454(int *param_1)

{
  char cVar1;
  int iVar2;
  
  if ((param_1[0x20] == 0x16) && (iVar2 = FUN_4012a344(param_1), iVar2 != 0)) {
    return iVar2;
  }
  iVar2 = param_1[0x20];
  if (iVar2 == 0x14) {
    if (param_1[0x21] != 1) {
      return -0x7200;
    }
    if (*(char *)param_1[0x1e] != '\x01') {
      return -0x7200;
    }
    if (*(char *)(*param_1 + 5) != '\x01') {
      return 0;
    }
    if ((param_1[1] - 10U & 0xfffffffd) != 0) {
      if (param_1[0x11] == 0) {
        return -0x6700;
      }
      return -0x6480;
    }
  }
  else {
    if (iVar2 == 0x15) {
      if (param_1[0x21] != 2) {
        return -0x7200;
      }
      cVar1 = *(char *)param_1[0x1e];
      if (cVar1 == '\x02') {
        return -0x7780;
      }
      if (cVar1 != '\x01') {
        return -0x6680;
      }
      cVar1 = ((char *)param_1[0x1e])[1];
      if (cVar1 != '\0') {
        if (cVar1 != 'd') {
          return -0x6680;
        }
        return 0;
      }
      return -0x7880;
    }
    if (*(char *)(*param_1 + 5) != '\x01') {
      return 0;
    }
    if (((iVar2 == 0x17) && (param_1[1] != 0x10)) && ((param_1[2] != 1 || (param_1[1] != 2)))) {
      return -0x6680;
    }
  }
  if ((param_1[0x11] != 0) && (param_1[1] == 0x10)) {
    FUN_4012ca94(param_1);
  }
  return 0;
}


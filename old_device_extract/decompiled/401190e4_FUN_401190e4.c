// Function : FUN_401190e4
// Address  : 0x401190e4
// Size     : 283 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_401190e4(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  if (DAT_3ffc8540 != '\0') {
    iVar2 = 0;
    cVar1 = '\0';
    if ((DAT_3ffc8540 != '\x03') || (iVar3 = 0, DAT_3ffc8541 != '\0')) {
      iVar2 = 0;
      cVar1 = '\0';
      if ((DAT_3ffc8540 != '\x05') || (iVar3 = 0, DAT_3ffc8541 != '\0')) {
        iVar2 = 0;
        cVar1 = '\0';
        if ((DAT_3ffc8540 != '\x04') || (iVar3 = 0, DAT_3ffc8541 != '\0')) {
          cVar1 = -1;
          iVar3 = -1;
          if ((DAT_3ffc8540 == '\x02') && ((DAT_3ffc8541 == '\0' && (_DAT_3ffc8544 != -1)))) {
            cVar1 = '\0';
            iVar3 = _DAT_3ffc8544;
          }
          iVar2 = (int)cVar1;
          if (iVar2 == -1) {
            if (((_DAT_3ffc853c == 0) && (DAT_3ffc8540 == '\x01')) && (DAT_3ffc8541 == '\0')) {
              cVar1 = '\0';
            }
            iVar3 = 0;
            iVar2 = (int)cVar1;
            if (iVar2 == -1) {
              if ((DAT_3ffc8540 == '\x01') && (DAT_3ffc8541 == '\0')) {
                cVar1 = '\0';
                iVar3 = _DAT_3ffc8544;
              }
              iVar2 = (int)cVar1;
              if (iVar2 == -1) {
                return cVar1;
              }
            }
          }
        }
      }
    }
    FUN_40119080(iVar2,5,iVar3);
  }
  return cVar1;
}


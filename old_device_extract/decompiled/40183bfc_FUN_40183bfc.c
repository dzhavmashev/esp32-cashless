// Function : FUN_40183bfc
// Address  : 0x40183bfc
// Size     : 126 bytes


char * FUN_40183bfc(undefined4 *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_2 != 0) {
    pcVar2 = (char *)*param_1;
    while( true ) {
      pcVar4 = (char *)param_1[1];
      if (pcVar4 <= pcVar2 + param_3) break;
      iVar3 = 0;
      if (pcVar2[param_3] == '\0') {
        while( true ) {
          if (param_3 == iVar3) {
            if (pcVar2 != (char *)0x0) {
              return pcVar2;
            }
            goto LAB_40183c70;
          }
          if (*(char *)(param_2 + iVar3) != pcVar2[iVar3]) break;
          iVar3 = iVar3 + 1;
        }
      }
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
LAB_40183c70:
    if ((char *)param_1[2] < pcVar4 + param_3 + 1) {
      *(undefined1 *)(param_1 + 4) = 1;
    }
    else {
      param_1[1] = pcVar4 + param_3 + 1;
      if (pcVar4 != (char *)0x0) {
        for (iVar3 = 0; param_3 != iVar3; iVar3 = iVar3 + 1) {
          pcVar4[iVar3] = *(char *)(param_2 + iVar3);
        }
        pcVar4[param_3] = '\0';
        return pcVar4;
      }
    }
  }
  return (char *)0x0;
}


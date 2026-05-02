// Function : FUN_40183dc0
// Address  : 0x40183dc0
// Size     : 209 bytes


bool FUN_40183dc0(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int *piVar6;
  
  if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
    piVar6 = (int *)*param_1;
    if (piVar6 == (int *)0x0) {
      if (param_2 == (undefined4 *)0x0) {
        return false;
      }
      *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80;
      return true;
    }
    uVar3 = param_1[2];
  }
  else {
    uVar3 = (uint)param_1[3] >> 0x18 & 0x7f;
    piVar6 = param_1;
  }
  if (param_2 == (undefined4 *)0x0) {
    return false;
  }
  pcVar2 = (char *)*param_3;
  while( true ) {
    pcVar5 = (char *)param_3[1];
    if (pcVar5 <= pcVar2 + uVar3) break;
    uVar4 = 0;
    if (pcVar2[uVar3] == '\0') {
      while( true ) {
        if (uVar4 == uVar3) {
          if (pcVar2 != (char *)0x0) goto LAB_40183e38;
          goto LAB_40183e54;
        }
        if (*(char *)((int)piVar6 + uVar4) != pcVar2[uVar4]) break;
        uVar4 = uVar4 + 1;
      }
    }
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
LAB_40183e54:
  if ((char *)param_3[2] < pcVar5 + uVar3 + 1) {
    *(undefined1 *)(param_3 + 4) = 1;
  }
  else {
    param_3[1] = pcVar5 + uVar3 + 1;
    if (pcVar5 != (char *)0x0) {
      for (uVar4 = 0; uVar4 != uVar3; uVar4 = uVar4 + 1) {
        pcVar5[uVar4] = *(char *)((int)piVar6 + uVar4);
      }
      pcVar5[uVar3] = '\0';
      pcVar2 = pcVar5;
LAB_40183e38:
      *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80 | 5;
      *param_2 = pcVar2;
      param_2[1] = uVar3;
      goto LAB_40183e72;
    }
  }
  *(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) & 0x80;
  pcVar2 = (char *)0x0;
LAB_40183e72:
  return pcVar2 != (char *)0x0;
}


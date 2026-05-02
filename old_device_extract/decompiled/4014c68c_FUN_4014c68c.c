// Function : FUN_4014c68c
// Address  : 0x4014c68c
// Size     : 213 bytes


void FUN_4014c68c(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  byte local_30 [48];
  
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    FUN_40147fe4(1,0x800,1,"memory!",&DAT_3f423a7d,0x12a);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = FUN_40186948(param_1);
  if (iVar1 == 0) {
    uVar3 = 3;
    if (param_2 == '\0') {
      local_30[0] = 'u';
      memw();
      local_30[2] = 't';
      memw();
      local_30[1] = 'i';
      local_30[3] = 'e';
      memw();
      if (*(byte *)((int)param_1 + 0x73) < 5) {
        for (piVar4 = param_1;
            piVar4 != (int *)((int)param_1 + (uint)*(byte *)((int)param_1 + 0x73));
            piVar4 = (int *)((int)piVar4 + 1)) {
          iVar5 = 0;
          iVar1 = 4;
          while (local_30[iVar5] != (*(byte *)(piVar4 + 0x1d) & 0x7f)) {
            iVar5 = iVar5 + 1;
            iVar1 = iVar1 + -1;
            if (iVar1 == 0) goto LAB_4014c729;
          }
        }
        uVar3 = 1;
      }
      else {
        memw();
LAB_4014c729:
        uVar3 = 2;
      }
    }
    *(undefined1 *)((int)param_1 + 0x31) = uVar3;
    memw();
    if (*(byte *)(iVar2 + 0x168) < *(byte *)((int)param_1 + 0x31)) {
      *(byte *)((int)param_1 + 0x32) = *(byte *)(iVar2 + 0x168);
      memw();
      memw();
    }
    else {
      *(byte *)((int)param_1 + 0x32) = *(byte *)((int)param_1 + 0x31);
      memw();
    }
    if (*(char *)(iVar2 + 0x168) != '\x04') {
      return;
    }
    memw();
  }
  *(undefined1 *)((int)param_1 + 0x32) = 4;
  memw();
  memw();
  return;
}


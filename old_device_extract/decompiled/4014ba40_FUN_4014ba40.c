// Function : FUN_4014ba40
// Address  : 0x4014ba40
// Size     : 403 bytes


void FUN_4014ba40(int *param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  iVar1 = FUN_4015b1d4();
  if ((param_1 == (int *)0x0) || (iVar3 = *param_1, iVar3 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x768);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_4014b4e4(param_1,param_2);
  if ((*(uint *)(iVar3 + 0x160) & 0xc) != 0) {
    uVar4 = param_1[3];
    if ((*(ushort *)(param_1 + 0x57) & 0xc) == 0) {
      uVar4 = uVar4 & 0xffffdfff | 0x1000;
    }
    else if ((*(ushort *)(param_1 + 0x57) & 0xc) == 4) {
      uVar4 = uVar4 | 0x3000;
    }
    else {
      uVar4 = uVar4 & 0xffffcfff;
    }
    param_1[3] = uVar4;
  }
  uVar4 = param_1[3];
  param_1[3] = uVar4 & 0xfffe7fff;
  if (((*(ushort *)(param_1 + 0x57) & 0x20) != 0) &&
     ((*(uint *)(*param_1 + 0x158) & 0x4000000) != 0)) {
    param_1[3] = uVar4 & 0xfffe7fff | 0x8000;
  }
  if (((*(ushort *)(param_1 + 0x57) & 0x40) != 0) &&
     ((*(uint *)(*param_1 + 0x158) & 0x8000000) != 0)) {
    param_1[3] = param_1[3] | 0x10000;
  }
  if ((*param_3 == -0x23) && (param_3 = param_3 + 4, param_3 == (char *)0x0)) {
    memw();
    FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x643);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(char *)((int)param_1 + 0x15f) = param_3[2];
  memw();
  bVar5 = param_3[3] & 3;
  *(byte *)(param_1 + 0x58) = bVar5;
  memw();
  *(byte *)((int)param_1 + 0x161) = param_3[4] & 3;
  memw();
  *(byte *)((int)param_1 + 0x162) = param_3[6] & 0x7f;
  memw();
  uVar4 = param_1[3];
  param_1[3] = uVar4 | 0xc0;
  cVar2 = '\0';
  if (((param_3[3] & 4U) != 0) &&
     (((*(uint *)(iVar3 + 0x158) & 0x1000000) != 0 && (cVar2 = '\x01', bVar5 != 1)))) {
    cVar2 = '\x02';
    if (bVar5 != 3) {
      cVar2 = '\0';
    }
  }
  if (((param_3[3] & 8U) == 0) || ((*(uint *)(iVar3 + 0x158) & 0x20000000) == 0)) {
    param_1[3] = uVar4 & 0xffffbfff | 0xc0;
  }
  else {
    param_1[3] = uVar4 | 0x40c0;
    memw();
  }
  if (cVar2 != (char)param_1[0x2b]) {
    *(char *)(param_1 + 0x2b) = cVar2;
    memw();
    if (param_1 == *(int **)(iVar3 + 0xe4)) {
      memw();
      FUN_40147fe4(1,8,5,0x3f435c62);
      *(char *)(iVar3 + 0x157) = cVar2;
      memw();
      memw();
      FUN_4014b690((int)param_1 + 0xab);
    }
  }
  if ((*(char *)(iVar1 + 1) != cVar2) && (cVar2 != '\0')) {
    FUN_40147fe4(1,8,5,0x3f435c42,*(char *)(iVar1 + 1),cVar2);
  }
  return;
}


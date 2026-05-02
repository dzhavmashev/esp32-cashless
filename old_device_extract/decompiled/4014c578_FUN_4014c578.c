// Function : FUN_4014c578
// Address  : 0x4014c578
// Size     : 261 bytes


void FUN_4014c578(int *param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  
  cVar1 = *(char *)((int)param_1 + 0x32);
  if (cVar1 != '\x04') {
    cVar2 = *(char *)((int)param_1 + 0x2ef);
    *(byte *)((int)param_1 + 0x2ef) = *(byte *)((int)param_1 + 0x2ee);
    memw();
    if (*(byte *)((int)param_1 + 0x2ee) < *(byte *)((int)param_1 + 0x2ed)) {
      *(byte *)((int)param_1 + 0x2ef) = *(byte *)((int)param_1 + 0x2ed);
      *(undefined1 *)((int)param_1 + 0x32) = 2;
      memw();
    }
    if (*(byte *)((int)param_1 + 0x2ef) < *(byte *)(param_1 + 0xbb)) {
      *(byte *)((int)param_1 + 0x2ef) = *(byte *)(param_1 + 0xbb);
      *(undefined1 *)((int)param_1 + 0x32) = 1;
      memw();
    }
    cVar3 = *(char *)((int)param_1 + 0x32);
    if (cVar3 == '\x01') {
      cVar4 = (char)param_1[0xbc];
      memw();
    }
    else if (cVar3 == '\x02') {
      cVar4 = *(char *)((int)param_1 + 0x2f1);
    }
    else {
      cVar4 = *(char *)((int)param_1 + 0x2f2);
    }
    if (((*(byte *)((int)param_1 + 10) & 4) == 0) ||
       ((cVar2 == *(char *)((int)param_1 + 0x2ef) && (*(char *)((int)param_1 + 0x2f3) == cVar4)))) {
      *(char *)((int)param_1 + 0x2f3) = cVar4;
    }
    else {
      memw();
      FUN_40147fe4(1,8,4,0x3f4336ba,cVar2,cVar1,*(undefined1 *)((int)param_1 + 0x2f3),
                   *(char *)((int)param_1 + 0x2ef),cVar3,cVar4);
      memw();
      FUN_40147fe4(1,8,4,0x3f43367f,(char)param_1[0xbc],*(undefined1 *)((int)param_1 + 0x2f1),
                   *(undefined1 *)((int)param_1 + 0x2f2),(char)param_1[0xbb],
                   *(undefined1 *)((int)param_1 + 0x2ed),*(undefined1 *)((int)param_1 + 0x2ee));
      *(char *)((int)param_1 + 0x2f3) = cVar4;
      memw();
      iVar5 = *param_1;
      if ((iVar5 != 0) && ((param_1 == *(int **)(iVar5 + 0xe4) && (*(int *)(iVar5 + 0x98) == 5)))) {
        memw();
        FUN_40147fe4(1,8,4,0x3f433674);
        FUN_4015dcd0(1,param_1);
      }
    }
    *(undefined1 *)(param_1 + 0xbc) = 0;
    *(undefined1 *)((int)param_1 + 0x2f1) = 0;
    *(undefined1 *)((int)param_1 + 0x2f2) = 0;
    *(undefined1 *)(param_1 + 0xbb) = 0;
    *(undefined1 *)((int)param_1 + 0x2ed) = 0;
    *(undefined1 *)((int)param_1 + 0x2ee) = 0;
    memw();
  }
  memw();
  return;
}


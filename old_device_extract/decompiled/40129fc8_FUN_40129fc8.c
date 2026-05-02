// Function : FUN_40129fc8
// Address  : 0x40129fc8
// Size     : 479 bytes


int FUN_40129fc8(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x44);
  if (*(char *)(iVar3 + 7) != '\x01') {
    *(int **)(iVar3 + 0x250) = *(int **)(iVar3 + 0x24c);
    *(int *)(iVar3 + 0x254) = **(int **)(iVar3 + 0x24c) + 0xc;
    memw();
    iVar3 = FUN_40129c30(param_1);
    if (iVar3 != 0) {
      return iVar3;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 7) = 1;
    memw();
  }
  do {
    piVar5 = *(int **)(*(int *)(param_1 + 0x44) + 0x250);
    if (piVar5 == (int *)0x0) {
      memw();
      iVar3 = FUN_40129bc8(param_1);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = *(int *)(param_1 + 0x44);
      if (*(int *)(param_1 + 4) != 0x10) {
        *(undefined1 *)(iVar3 + 7) = 2;
        memw();
        memw();
        FUN_40185804(param_1,*(undefined4 *)(iVar3 + 0x248));
        return 0;
      }
      *(undefined1 *)(iVar3 + 7) = 3;
      memw();
      memw();
      return 0;
    }
    cVar1 = *(char *)(param_1 + 0xb4);
    if (((char)piVar5[2] == '\x16') && (*(char *)*piVar5 == '\x14')) {
      if ((*(char **)(*(int *)(param_1 + 0x44) + 0x254) == (char *)*piVar5 + 0xc) &&
         (iVar3 = FUN_40129c30(param_1), iVar3 != 0)) {
        return iVar3;
      }
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    iVar3 = FUN_40129d28(param_1);
    if (iVar3 < 0) {
      return iVar3;
    }
    if ((char)piVar5[2] == '\x14') {
      if (iVar3 == 0) goto LAB_4012a07a;
      (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_1 + 0xcc),*piVar5,piVar5[1]);
      iVar3 = piVar5[1];
      *(int *)(param_1 + 0xd4) = iVar3;
      *(uint *)(param_1 + 0xd0) = (uint)*(byte *)(piVar5 + 2);
      *(int *)(*(int *)(param_1 + 0x44) + 0x254) =
           *(int *)(*(int *)(param_1 + 0x44) + 0x254) + iVar3;
LAB_4012a0ae:
      iVar3 = *(int *)(param_1 + 0x44);
      if ((uint)(*piVar5 + piVar5[1]) <= *(uint *)(iVar3 + 0x254)) {
        piVar5 = (int *)piVar5[3];
        *(int **)(iVar3 + 0x250) = piVar5;
        iVar6 = 0;
        if (piVar5 != (int *)0x0) {
          iVar6 = *piVar5 + 0xc;
        }
        *(int *)(iVar3 + 0x254) = iVar6;
      }
      memw();
      iVar3 = FUN_40129e24(param_1,cVar1 == '\x01');
    }
    else {
      if (0xb < iVar3) {
        uVar4 = iVar3 - 0xc;
        if ((uVar4 != 0) || (piVar5[1] + -0xc == 0)) {
          iVar8 = *(int *)(*(int *)(param_1 + 0x44) + 0x254);
          iVar6 = iVar8 - (*piVar5 + 0xc);
          uVar7 = (piVar5[1] + -0xc) - iVar6;
          iVar3 = (uVar7 < uVar4) * uVar7 + (uVar7 >= uVar4) * uVar4;
          memw();
          (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_1 + 0xcc),*piVar5,6);
          *(char *)(*(int *)(param_1 + 0xcc) + 6) = (char)((uint)iVar6 >> 0x10);
          memw();
          *(char *)(*(int *)(param_1 + 0xcc) + 7) = (char)((uint)iVar6 >> 8);
          memw();
          *(char *)(*(int *)(param_1 + 0xcc) + 8) = (char)iVar6;
          memw();
          *(char *)(*(int *)(param_1 + 0xcc) + 9) = (char)((uint)iVar3 >> 0x10);
          memw();
          *(char *)(*(int *)(param_1 + 0xcc) + 10) = (char)((uint)iVar3 >> 8);
          memw();
          *(char *)(*(int *)(param_1 + 0xcc) + 0xb) = (char)iVar3;
          memw();
          memw();
          (*(code *)&SUB_4008b3d0)(*(int *)(param_1 + 0xcc) + 0xc,iVar8,iVar3);
          *(int *)(param_1 + 0xd4) = iVar3 + 0xc;
          *(uint *)(param_1 + 0xd0) = (uint)*(byte *)(piVar5 + 2);
          *(int *)(*(int *)(param_1 + 0x44) + 0x254) =
               *(int *)(*(int *)(param_1 + 0x44) + 0x254) + iVar3;
          memw();
          goto LAB_4012a0ae;
        }
      }
      if ((bVar2) && (iVar3 = FUN_40129c30(param_1), iVar3 != 0)) {
        return iVar3;
      }
LAB_4012a07a:
      iVar3 = FUN_40129bc8(param_1);
    }
    if (iVar3 != 0) {
      return iVar3;
    }
  } while( true );
}


// Function : FUN_40189844
// Address  : 0x40189844
// Size     : 176 bytes


void FUN_40189844(int param_1,uint *param_2)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  if ((param_1 == 0) || (uVar3 = *param_2, (uVar3 & 0x2000000) != 0)) goto LAB_401898f8;
  if ((uVar3 & 0xc) == 8) {
    param_2[7] = *(uint *)(param_1 + 0x60);
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      if ((uVar3 & 2) != 0) {
        puVar4 = *(undefined1 **)(param_1 + 0x68);
        goto LAB_401898ea;
      }
      if (-1 < (char)*(byte *)(param_1 + 0xb)) {
        FUN_40164ba0();
      }
      goto LAB_401898ed;
    }
    uVar2 = *(undefined1 *)(param_1 + 8);
    memw();
  }
  else {
    param_2[7] = *(uint *)(param_1 + 100);
    if ((*(byte *)(param_1 + 0xb) & 2) != 0) {
      uVar2 = *(undefined1 *)(param_1 + 9);
      memw();
      goto LAB_401898f2;
    }
    if ((char)*(byte *)(param_1 + 0xb) < '\0') {
      uVar3 = param_2[4];
      if ((uVar3 & 0x80000) == 0) {
        if ((uVar3 & 0x10000) == 0) {
          if (((uVar3 & 0x20000) == 0) || (iVar1 = FUN_4015c2cc(param_1), iVar1 != 0)) {
            puVar4 = &DAT_3ffc0484;
            goto LAB_401898ea;
          }
          goto LAB_401898c5;
        }
      }
      else {
LAB_401898c5:
        iVar1 = FUN_40189c14();
        if (iVar1 == 0) goto LAB_401898ed;
      }
      puVar4 = &DAT_3ffc06c4;
    }
    else {
      if ((((uVar3 & 0x200800) == 0) || (*(char *)(param_1 + 0x82) == '\0')) ||
         (param_2[7] = (uint)&DAT_3ffc06d0, *(char *)(param_1 + 0x87) == '\0')) goto LAB_401898ed;
      puVar4 = &DAT_3ffc06b8;
    }
LAB_401898ea:
    param_2[7] = (uint)puVar4;
LAB_401898ed:
    uVar2 = *(undefined1 *)param_2[7];
  }
LAB_401898f2:
  *(undefined1 *)(param_2 + 3) = uVar2;
  memw();
LAB_401898f8:
  memw();
  return;
}


// Function : FUN_4012b2e8
// Address  : 0x4012b2e8
// Size     : 513 bytes


undefined1 * FUN_4012b2e8(int *param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  puVar5 = (undefined1 *)0xffff8f00;
  if (((((param_1 == (int *)0x0) || (*param_1 == 0)) ||
       ((*(char *)(*param_1 + 5) == '\x01' &&
        ((puVar5 = (undefined1 *)FUN_40129bc8(param_1), puVar5 != (undefined1 *)0x0 ||
         (((param_1[0x11] != 0 && (*(char *)(param_1[0x11] + 7) == '\x01')) &&
          (puVar5 = (undefined1 *)FUN_40129fc8(param_1), puVar5 != (undefined1 *)0x0)))))))) ||
      ((puVar5 = (undefined1 *)FUN_40129140(param_1), puVar5 != (undefined1 *)0xffff9500 &&
       (puVar5 != (undefined1 *)0x0)))) ||
     ((param_1[1] != 0x10 &&
      ((puVar5 = (undefined1 *)FUN_4012c9dc(param_1), puVar5 != (undefined1 *)0xffff9500 &&
       (puVar5 != (undefined1 *)0x0)))))) {
    return puVar5;
  }
LAB_4012b315:
  if (param_1[0x1f] != 0) {
    uVar6 = param_1[0x21];
    puVar5 = (undefined1 *)((param_3 < uVar6) * param_3 + (param_3 >= uVar6) * uVar6);
    if (param_3 != 0) {
      (*(code *)&SUB_4008b3d0)(param_2,param_1[0x1f],puVar5);
      param_1[0x21] = param_1[0x21] - (int)puVar5;
    }
    memw();
    FUN_4013ae54(param_1[0x1f],puVar5);
    if (param_1[0x21] == 0) {
      param_1[0x1f] = 0;
      param_1[0x2c] = 0;
    }
    else {
      param_1[0x1f] = (int)(puVar5 + param_1[0x1f]);
      memw();
    }
    memw();
    return puVar5;
  }
  if (((code *)param_1[0x18] != (code *)0x0) &&
     (iVar2 = (*(code *)param_1[0x18])(param_1[0x16]), iVar2 == -1)) {
    FUN_40185804(param_1,*(undefined4 *)(*param_1 + 0x14));
  }
  puVar5 = (undefined1 *)FUN_4012a960(param_1,1);
  if ((puVar5 != (undefined1 *)0x0) ||
     (((param_1[0x21] == 0 && (param_1[0x20] == 0x17)) &&
      (puVar5 = (undefined1 *)FUN_4012a960(param_1,1), puVar5 != (undefined1 *)0x0)))) {
    if (puVar5 != (undefined1 *)0xffff8d80) {
      return puVar5;
    }
    return (undefined1 *)0x0;
  }
  iVar2 = param_1[0x20];
  if (iVar2 == 0x16) {
    iVar2 = *param_1;
    if (*(char *)(iVar2 + 4) == '\0') {
      cVar1 = *(char *)(iVar2 + 5);
      if (*(char *)param_1[0x1e] != '\0') {
joined_r0x4012b457:
        if (cVar1 != '\x01') {
LAB_4012b442:
          return &DAT_ffff8900;
        }
        goto LAB_4012b315;
      }
      if (cVar1 != '\x01') {
        if (param_1[0x2a] == 4) goto LAB_4012b408;
        goto LAB_4012b442;
      }
      if (param_1[0x2a] != 0xc) goto LAB_4012b315;
    }
    else if ((*(char *)(iVar2 + 4) == '\x01') && (*(char *)param_1[0x1e] != '\x01')) {
      cVar1 = *(char *)(iVar2 + 5);
      goto joined_r0x4012b457;
    }
LAB_4012b408:
    if ((*(char *)(iVar2 + 0xd) != '\0') && ((param_1[0x80] != 0 || (*(char *)(iVar2 + 7) != '\0')))
       ) {
      if (*(short *)(iVar2 + 4) == 0x100) {
        param_1[2] = 3;
      }
      memw();
      puVar5 = (undefined1 *)FUN_4012cd4c(param_1);
      if (puVar5 != (undefined1 *)0xffff9500) goto LAB_4012b433;
      goto LAB_4012b315;
    }
    if (param_1[5] < 1) {
      return (undefined1 *)0xffff9400;
    }
    puVar5 = (undefined1 *)FUN_4012a73c(param_1,1,100);
  }
  else {
    if (((param_1[2] == 3) && (iVar4 = *(int *)(*param_1 + 0x20), -1 < iVar4)) &&
       (iVar3 = param_1[3], param_1[3] = iVar3 + 1, iVar4 < iVar3 + 1)) {
      memw();
      goto LAB_4012b442;
    }
    if (iVar2 == 0x15) {
      return (undefined1 *)0xffff9700;
    }
    if (iVar2 != 0x17) goto LAB_4012b442;
    param_1[0x1f] = param_1[0x1e];
    if (param_1[1] == 0x10) {
      memw();
      FUN_40185804(param_1,0);
    }
    if ((*(char *)(*param_1 + 4) != '\x01') || (param_1[2] != 3)) goto LAB_4012b315;
    puVar5 = (undefined1 *)FUN_4012c33c(param_1);
  }
LAB_4012b433:
  if (puVar5 != (undefined1 *)0x0) {
    return puVar5;
  }
  goto LAB_4012b315;
}


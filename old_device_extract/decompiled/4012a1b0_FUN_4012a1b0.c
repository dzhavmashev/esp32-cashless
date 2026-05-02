// Function : FUN_4012a1b0
// Address  : 0x4012a1b0
// Size     : 392 bytes


uint FUN_4012a1b0(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if ((param_1[10] == 0) && (param_1[0xb] == 0)) {
    return 0xffff8f00;
  }
  iVar1 = param_1[0x1b];
  if (0x414dU - (iVar1 - param_1[0x19]) < param_2) {
    return 0xffff8f00;
  }
  if (*(char *)(*param_1 + 5) == '\x01') {
    uVar4 = param_1[0x24];
    if (uVar4 != 0) {
      if ((uint)param_1[0x22] < uVar4) {
        return 0xffff9400;
      }
      iVar5 = param_1[0x22] - uVar4;
      param_1[0x22] = iVar5;
      if (iVar5 != 0) {
        memw();
        (*(code *)&SUB_4008b4c8)(iVar1,iVar1 + uVar4);
      }
      param_1[0x24] = 0;
    }
    if (param_2 <= (uint)param_1[0x22]) {
      return 0;
    }
    if (param_1[0x22] != 0) {
      return 0xffff9400;
    }
    memw();
    iVar1 = FUN_4018581c(param_1);
    if (iVar1 == 0) {
      if (param_1[1] == 0x10) {
        uVar6 = *(undefined4 *)(*param_1 + 0x14);
      }
      else {
        uVar6 = *(undefined4 *)(param_1[0x11] + 0x248);
      }
      if ((code *)param_1[0xb] == (code *)0x0) {
        uVar4 = (*(code *)param_1[10])
                          (param_1[0xc],param_1[0x1b],0x414d - (param_1[0x1b] - param_1[0x19]),uVar6
                          );
      }
      else {
        uVar4 = (*(code *)param_1[0xb])();
      }
      if (uVar4 == 0) {
        return 0xffff8d80;
      }
      if (uVar4 != 0xffff9800) {
        if (-1 < (int)uVar4) {
          param_1[0x22] = uVar4;
          memw();
          return 0;
        }
        return uVar4;
      }
    }
    FUN_40185804(param_1,0);
    iVar1 = *param_1;
    if (param_1[1] == 0x10) {
      if ((*(char *)(iVar1 + 4) == '\x01') && (param_1[2] == 3)) {
        uVar4 = FUN_4012c33c(param_1);
LAB_4012a2cb:
        if (uVar4 == 0) {
          return 0xffff9700;
        }
        return uVar4;
      }
    }
    else {
      iVar5 = param_1[0x11];
      uVar3 = *(uint *)(iVar1 + 0x1c);
      uVar4 = *(uint *)(iVar5 + 0x248);
      if (uVar4 < uVar3) {
        if (uVar4 != *(uint *)(iVar1 + 0x18)) {
          *(undefined2 *)(iVar5 + 0x268) = 0x1fc;
          memw();
        }
        uVar2 = uVar4 << 1;
        if ((uVar3 < uVar2) || (uVar2 < uVar4)) {
          uVar2 = uVar3;
        }
        *(uint *)(iVar5 + 0x248) = uVar2;
        memw();
        uVar4 = FUN_40129fc8(param_1);
        goto LAB_4012a2cb;
      }
    }
  }
  else {
    while( true ) {
      uVar4 = param_1[0x22];
      if (param_2 <= uVar4) {
        memw();
        return 0;
      }
      iVar1 = FUN_4018581c(param_1);
      if (iVar1 != 0) break;
      uVar4 = param_2 - uVar4;
      if ((code *)param_1[0xb] == (code *)0x0) {
        uVar3 = (*(code *)param_1[10])(param_1[0xc],param_1[0x1b] + param_1[0x22],uVar4);
      }
      else {
        uVar3 = (*(code *)param_1[0xb])
                          (param_1[0xc],param_1[0x1b] + param_1[0x22],uVar4,
                           *(undefined4 *)(*param_1 + 0x14));
      }
      if (uVar3 == 0) {
        return 0xffff8d80;
      }
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      if (uVar4 < uVar3) {
        return 0xffff9400;
      }
      param_1[0x22] = param_1[0x22] + uVar3;
    }
  }
  return 0xffff9800;
}


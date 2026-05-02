// Function : FUN_40152e4c
// Address  : 0x40152e4c
// Size     : 160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40152e4c(int param_1,int param_2,undefined4 *param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_3ffc8a34 == '\0') {
    iVar3 = _DAT_3ffc8800;
    if ((param_1 == 0) || (iVar3 = _DAT_3ffc8804, param_1 == 1)) {
      if (iVar3 == 0) {
        uVar2 = 0x3007;
      }
      else if (*(int *)(iVar3 + 0x98) == 5) {
        if (param_1 == 0) {
          iVar3 = *(int *)(iVar3 + 0xe4);
        }
        else {
          iVar3 = FUN_40187c28(param_2);
        }
        if ((iVar3 != 0) &&
           ((*(short *)(iVar3 + 0x26) != 0 || ((*(uint *)(iVar3 + 0xc) & 0x20000) == 0)))) {
          sVar1 = CONCAT11(*(undefined1 *)(param_2 + 0xc),*(undefined1 *)(param_2 + 0xd));
          iVar4 = FUN_40189c54(iVar3,sVar1 == -0x774c || sVar1 == -0x7772);
          if (iVar4 == 0) {
            *param_3 = 0x3016;
            iVar3 = 0;
          }
          memw();
          return iVar3;
        }
        uVar2 = 0x3015;
      }
      else {
        uVar2 = 0x3006;
      }
    }
    else {
      uVar2 = 0x3004;
    }
  }
  else {
    uVar2 = 0x3002;
  }
  *param_3 = uVar2;
  memw();
  return 0;
}


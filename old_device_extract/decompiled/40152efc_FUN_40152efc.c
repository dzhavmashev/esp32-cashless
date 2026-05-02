// Function : FUN_40152efc
// Address  : 0x40152efc
// Size     : 329 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40152efc(uint param_1,int param_2,ushort param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 local_40 [4];
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  
  uVar1 = param_1 & 0xff;
  local_40[0] = 0;
  uStack_30 = param_5;
  if ((param_2 == 0) || (param_3 == 0)) {
    memw();
    FUN_40147fe4(1,0x40,2,0x3f436b4f);
  }
  else {
    if (param_3 < 0x61d) {
      (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
      if (uVar1 == 0) {
        _DAT_3ffc7948 = _DAT_3ffc7948 + 1;
        memw();
      }
      else {
        _DAT_3ffc7944 = _DAT_3ffc7944 + 1;
      }
      puStack_2c = &DAT_3ffc791c;
      memw();
      iVar2 = FUN_40152e4c(uVar1,param_2,local_40);
      if (iVar2 == 0) {
        (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
        return local_40[0];
      }
      if ((((uVar1 == 1) && ((*(uint *)(iVar2 + 0xc) & 0x10) != 0)) && (param_4 == 0)) &&
         ((*(int *)(_DAT_3ffc8804 + 0x134) <= *(int *)(_DAT_3ffc8804 + 0x138) &&
          (0 < *(int *)(iVar2 + 0x108))))) {
        *(short *)(puStack_2c + 0x3a) = *(short *)(puStack_2c + 0x3a) + 1;
        memw();
        memw();
      }
      else {
        iVar2 = FUN_401519a4();
        if ((iVar2 == 0) || (iVar2 = FUN_40165f44(), iVar2 != 0)) {
          iVar2 = FUN_40151860(param_2,param_3,uStack_30);
        }
        else {
          iVar2 = FUN_401519e0(param_2,param_3);
        }
        if (iVar2 != 0) {
          *(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) =
               *(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) & 0xfff7ffff | (param_1 & 1) << 0x13;
          if ((_DAT_3ffc8864 == 0) || (param_4 != 1)) {
            uVar1 = *(uint *)(iVar2 + 0x1c) & 0xfffeffff;
          }
          else {
            uVar1 = *(uint *)(iVar2 + 0x1c) | 0x10000;
            memw();
          }
          *(uint *)(iVar2 + 0x1c) = uVar1;
          memw();
          local_40[0] = FUN_40151968();
          memw();
          (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
          return 0;
        }
      }
      (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
      return 0x101;
    }
    FUN_40147fe4(1,0x40,2,0x3f436b08,param_3);
  }
  return 0x102;
}


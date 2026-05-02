// Function : FUN_4011fc74
// Address  : 0x4011fc74
// Size     : 278 bytes


/* WARNING: Removing unreachable block (ram,0x4011fca6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011fc74(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  lVar6 = FUN_4011fe98();
  if (lVar6 != 0) {
    uVar7 = FUN_4011fe4c();
    if (CONCAT44(_DAT_3ffc6d0c,_DAT_3ffc6d08) <= uVar7) {
      uVar7 = CONCAT44(_DAT_3ffc6d0c,_DAT_3ffc6d08);
      if (_DAT_3ffc6d08 == 0 && _DAT_3ffc6d0c == 0) goto LAB_4011fc94;
      uVar8 = FUN_4011fe4c();
      uVar4 = (uint)(uVar8 >> 6);
      iVar1 = (int)((uVar8 >> 6) >> 0x20);
      uVar5 = _DAT_3ffc6d0c << 0x1a | _DAT_3ffc6d08 >> 6;
      uVar2 = uVar4 - uVar5;
      iVar3 = (iVar1 - (_DAT_3ffc6d0c >> 6)) - (uint)(uVar4 < uVar2);
      if ((iVar3 < 1) &&
         ((uVar7 = CONCAT44(_DAT_3ffc6d0c,_DAT_3ffc6d08), iVar3 != 0 ||
          (uVar7 = CONCAT44(_DAT_3ffc6d0c,_DAT_3ffc6d08), uVar2 == 0)))) goto LAB_4011fc94;
      if (_DAT_3ffc6d04 < 0) {
        iVar3 = (uint)(_DAT_3ffc6d00 + uVar2 < _DAT_3ffc6d00) + _DAT_3ffc6d04 + iVar3;
        if (iVar3 < 0) {
          lVar6 = lVar6 + CONCAT44(_DAT_3ffc6d0c >> 6,uVar5);
          uVar5 = (uint)lVar6;
          uVar4 = uVar5 - uVar4;
          lVar6 = CONCAT44(((int)((ulonglong)lVar6 >> 0x20) - iVar1) - (uint)(uVar5 < uVar4),uVar4);
          _DAT_3ffc6d00 = _DAT_3ffc6d00 + uVar2;
          _DAT_3ffc6d04 = iVar3;
        }
        else {
LAB_4011fd08:
          lVar6 = lVar6 + CONCAT44(_DAT_3ffc6d04,_DAT_3ffc6d00);
          uVar8 = 0;
          memw();
        }
      }
      else {
        uVar4 = _DAT_3ffc6d00 - uVar2;
        iVar1 = (_DAT_3ffc6d04 - iVar3) - (uint)(_DAT_3ffc6d00 < uVar4);
        if ((iVar1 < 1) && ((iVar1 != 0 || (uVar4 == 0)))) goto LAB_4011fd08;
        lVar6 = lVar6 + CONCAT44(iVar3,uVar2);
        memw();
        _DAT_3ffc6d00 = uVar4;
        _DAT_3ffc6d04 = iVar1;
      }
      memw();
      _DAT_3ffc6d08 = uVar8;
      FUN_4011fe6c((int)lVar6,(int)((ulonglong)lVar6 >> 0x20));
      uVar7 = _DAT_3ffc6d08;
      goto LAB_4011fc94;
    }
  }
  uVar7 = 0;
LAB_4011fc94:
  _DAT_3ffc6d0c = (uint)(uVar7 >> 0x20);
  _DAT_3ffc6d08 = (uint)uVar7;
  memw();
  return;
}

